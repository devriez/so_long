/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:30:00 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 16:46:52 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int	DR[] = {-1, 1, 0, 0};
static const int	DC[] = {0, 0, -1, 1};

static void	bfs_setup(t_game *g, t_map *m, t_bfs_state *b)
{
	int	size;

	size = m->rows * m->columns;
	b->queue = malloc(sizeof(t_coord) * size);
	if (!b->queue)
		error_and_exit(g, "BFS queue allocation failed.\n");
	b->visited = malloc(sizeof(int) * size);
	if (!b->visited)
	{
		free(b->queue);
		error_and_exit(g, "Visited array alloc failed.\n");
	}
	ft_bzero(b->visited, sizeof(int) * size);
	b->head = 0;
	b->tail = 0;
	b->found_collectibles = 0;
	b->exit_reachable = 0;
}

static void	bfs_enqueue_if_valid(t_map *m, t_bfs_state *b, int nc, int nr)
{
	char	t;

	if (nr >= 0 && nc >= 0 && nr < m->rows && nc < m->columns && \
		!b->visited[nr * m->columns + nc])
	{
		t = m->arr[nr][nc];
		if (t == FLOOR || t == COIN || t == EXIT || t == PLAYER)
		{
			b->queue[b->tail++] = (t_coord){nc, nr};
			b->visited[nr * m->columns + nc] = 1;
		}
	}
}

static void	bfs_run(t_map *m, t_bfs_state *b)
{
	t_coord	c;
	int		i;

	b->queue[b->tail++] = (t_coord){m->plr_x, m->plr_y};
	b->visited[m->plr_y * m->columns + m->plr_x] = 1;
	while (b->head < b->tail)
	{
		c = b->queue[b->head++];
		if (m->arr[c.y][c.x] == COIN)
			b->found_collectibles++;
		if (m->arr[c.y][c.x] == EXIT)
			b->exit_reachable = 1;
		i = 0;
		while (i < 4)
		{
			bfs_enqueue_if_valid(m, b, c.x + DC[i], c.y + DR[i]);
			i++;
		}
	}
	free(b->queue);
	free(b->visited);
}

void	check_valid_path(t_game *g, t_map *m)
{
	t_bfs_state	b;

	bfs_setup(g, m, &b);
	bfs_run(m, &b);
	if (!(b.found_collectibles == m->coins && b.exit_reachable))
		error_and_exit(g, "Error\nNo valid path on map.\n");
}
