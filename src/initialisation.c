/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/07/11 12:21:54 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	init_sprite(t_game *game, char * path_to_file)
{
	t_image sprite;

	sprite.ptr = mlx_xpm_file_to_image(game->mlx, \
										path_to_file, \
										&sprite.x_size, \
										&sprite.y_size);
	return (sprite);
}

void	init_sprites_img(t_game *game)
{
	game->plr_front = init_sprite(game, PLAYER_FRONT);
	game->plr_back = init_sprite(game, PLAYER_BACK);
	game->plr_left = init_sprite(game, PLAYER_LEFT);
	game->plr_right = init_sprite(game, PLAYER_RIGHT);
	game->plr_current_img = game->plr_front;
	game->coin = init_sprite(game, COIN_PATH);
	game->exit_closed = init_sprite(game, EXIT_CLOSED);
	game->exit_opend = init_sprite(game, EXIT_OPENED);
	game->floor = init_sprite(game, FLOOR);
	game->wall = init_sprite(game, WALL);
}

int	count_sprites_numb(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(game->map.arr[y])
	{
		x = 0;
		while(game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == COIN)
				game->map.coins ++;
			else if (game->map.arr[y][x] == EXIT)
				game->map.exits ++;
			else if (game->map.arr[y][x] == PLAYER)
				game->map.players ++;
			else if (game->map.arr[y][x] != FLOOR && \
					game->map.arr[y][x] != WALL)
				game->map.invalid_sprites ++;
			x ++;
		}
		y ++;
	}
}

void	set_sprites_num_to_zero(t_game *game)
{
	game->map.rows = 0;
	game->map.coins = 0;
	game->map.exits = 0;
	game->map.players = 0;
	game->map.invalid_sprites = 0;
}

void init_map(t_game *game, char *map_path)
{
	int		file;
	char	*new_line;
	char	*map_temp;

	file = open(map_path, O_RDONLY);
	if (file == -1)
		error_and_exit("Error with opening map's file");
	map_temp = ft_strdup("");
	set_sprites_num_to_zero(game);
	while (true)
	{
		new_line = get_next_line(file);
		if (new_line == NULL)
			break ;
		map_temp = ft_strappend(map_temp, new_line);
		free(new_line);
		game->map.rows++;
	}
	close(file);
	game->map.arr = ft_split(map_temp, '\n');
	free(map_temp);
	count_sprites_numb(game);
}

void	init_player_image(t_game *game)
{
	game->plr_left.ptr = mlx_xpm_file_to_image(game->mlx, \
											PLAYER_LEFT, \
											&game->plr_left.x_size, \
											&game->plr_left.y_size);
	game->plr_right.ptr = mlx_xpm_file_to_image(game->mlx, \
											PLAYER_RIGHT, \
											&game->plr_right.x_size, \
											&game->plr_right.y_size);
	game->plr_back.ptr = mlx_xpm_file_to_image(game->mlx, \
											PLAYER_BACK, \
											&game->plr_back.x_size, \
											&game->plr_back.y_size);
	game->plr_front.ptr = mlx_xpm_file_to_image(game->mlx, \
											PLAYER_FRONT, \
											&game->plr_front.x_size, \
											&game->plr_front.y_size);
	game->plr_current_img = game->plr_current_img;
}

void	init_player_coord(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(game->map.arr[y])
	{
		x = 0;
		while(game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == PLAYER)
			{
				game->map.plr_x = x;
				game->map.plr_y = y;
				break ;
			}
			x ++;
		}
		y ++;
	}
}

void	init_player(t_game *game)
{
	init_player_coord(game);
	init_player_image(game);
}
