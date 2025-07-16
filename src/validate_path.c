/* ************************************************************************** */
/* */
/* :::	  ::::::::   */
/* map_validation.c				   :+:	  :+:	:+:   */
/* +:+ +:+		 +:+	 */
/* By: amoiseik <amoiseik@student.42.fr>		  +#+  +:+	   +#+		*/
/* Hillsborough, FL, USA				 +#+#+#+#+#+   +#+		   */
/* Created: 2025/07/15 15:30:00 by amoiseik		  #+#	#+#			 */
/* Updated: 2025/07/15 15:30:00 by amoiseik		 ###   ########.fr	   */
/* */
/* ************************************************************************** */

#include "so_long.h" // Включаем наш заголовочный файл

static const	int DR[] = {-1, 1, 0, 0}; // (row delta)
static const	int DC[] = {0, 0, -1, 1}; // (column delta)

// --- 1. Функция для инициализации состояния BFS ---
void init_bfs_state(t_map *map, t_bfs_state *bfs)
{
	int	row;
	int	column;
	int	map_size;

	map_size = map->rows * map->columns;
	bfs->queue = (t_coord *)malloc(sizeof(t_coord) * map_size);
	if (!bfs->queue)
		error_and_exit("Error: Failed to allocate memory for BFS queue.");
	bfs->visited = (int *)malloc(sizeof(int) * map_size);
	if (!bfs->visited)
	{
		free(bfs->queue);
		error_and_exit("Error: Failed to allocate memory for array visited.\n");
	}
	bfs->head = 0;
	bfs->tail = 0;
	bfs->found_collectibles = 0;
	bfs->exit_reachable = 0;
	row = 0;
	while (row++ < map->rows)
	{
		column = 0;
		while (column++ < map->columns)
			bfs->visited[row * map->columns + column] = 0;
	}
}

// add in queue
void enqueue(t_bfs_state *bfs, int map_cols, int x, int y)
{
	t_coord coord;

	coord.x = x;
	coord.y = y;
	bfs->queue[bfs->tail] = coord;
	bfs->tail ++;
	bfs->visited[coord.y * map_cols + coord.x] = 1;
}

// extract from queue
t_coord dequeue(t_bfs_state *bfs)
{
	t_coord	extracted;

	extracted = bfs->queue[bfs->head];
	bfs->head ++;
	return (bfs->queue[bfs->head++]);
}

int is_valid_and_unvisited(t_map *map, t_bfs_state *bfs, int r, int c)
{
	if (r < 0 || r >= map->rows || c < 0 || c >= map->columns)
		return (0);
	if (map->arr[r][c] == WALL || bfs->visited[r * map->columns + c] == 1)
		return (0);
	return (1);
}

// --- 5. Основной цикл обхода BFS ---
void bfs_traverse(t_map *map, t_bfs_state *bfs)
{
	t_coord	current;
	int		i;
	int		new_row;
	int		new_column;

	enqueue(bfs, map->columns, map->plr_x, map->plr_y);
	while (bfs->head < bfs->tail) 
	{
		current = dequeue(bfs);
		if (map->arr[current.y][current.x] == COIN)
			bfs->found_collectibles ++;
		if (map->arr[current.y][current.x] == EXIT)
			bfs->exit_reachable = 1;
		i = 0;
		while (i < 4)
		{
			new_row = current.y + DR[i];
			new_column = current.x + DC[i];
			if (is_valid_and_unvisited(map, bfs, new_row, new_column))
				enqueue(bfs, map->columns, new_row, new_column);
			i ++;
		}
	}
	free(bfs->queue);
	free(bfs->visited);
}

void is_path_in_map(t_map *map)
{
	t_bfs_state	bfs_state;

	init_bfs_state(map, &bfs_state);
	bfs_traverse(map, &bfs_state);
	if(!(bfs_state.found_collectibles == map->coins && \
		bfs_state.exit_reachable))
		error_and_exit("No valid path in the map");
}
