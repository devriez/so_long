/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 16:51:29 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(t_game *game, char *map_path)
{
	int		file;
	char	*new_line;
	char	*map_temp;

	file = open(map_path, O_RDONLY);
	if (file == -1)
		error_and_exit(game, "Error with opening map's file");
	map_temp = ft_strdup("");
	while (true)
	{
		new_line = get_next_line(file);
		if (new_line == NULL)
			break ;
		map_temp = ft_strappend(map_temp, new_line);
		if (!map_temp)
			error_and_exit(game, "Memory alloc. failed during map reading");
		free(new_line);
	}
	close(file);
	game->map.arr = ft_split(map_temp, '\n');
	if (!game->map.arr || !game->map.arr[0])
		error_and_exit(game, "Error: empty or invalid map");
	free(map_temp);
}

static void	count_sprites_numb(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->arr[y])
	{
		x = 0;
		while (map->arr[y][x] != '\0')
		{
			if (map->arr[y][x] == COIN)
				map->coins ++;
			else if (map->arr[y][x] == EXIT)
				map->exits ++;
			else if (map->arr[y][x] == PLAYER)
				map->players ++;
			else if (map->arr[y][x] != FLOOR && map->arr[y][x] != WALL)
				map->invalid_sprites ++;
			x ++;
		}
		y ++;
	}
}

static void	init_player_coord(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == PLAYER)
			{
				game->map.plr_x = x;
				game->map.plr_y = y;
				game->map.arr[y][x] = FLOOR;
				return ;
			}
			x ++;
		}
		y ++;
	}
}

static void	set_map_size(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[i])
	{
		map->rows++;
		i ++;
	}
	map->columns = ft_strlen(map->arr[0]);
	map->width = game->plr_img.x_size * game->map.columns;
	map->height = game->plr_img.y_size * game->map.rows;
}

void	init_map(t_game *game, char *map_path)
{
	read_map(game, map_path);
	count_sprites_numb(&(game->map));
	init_player_coord(game);
	set_map_size(game, &(game->map));
}
