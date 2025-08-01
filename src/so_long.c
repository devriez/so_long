/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 15:35:33 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	t_map	map;

	map = game->map;
	if (keycode == ESQ_KEY)
		free_all_and_exit(game, EXIT_SUCCESS);
	player_img_change(keycode, game);
	player_xy_change(keycode, game, &(game->map));
	sprites_change(game, &(game->map));
	write_movements_num(game);
	if (map.arr[map.plr_y][map.plr_x] == EXIT && 
		game->exit.ptr == game->exit_opend.ptr)
		free_all_and_exit(game, EXIT_SUCCESS);
	return (0);
}

void	put_sprite_to_window(t_game *game, int x, int y)
{
	char	sprite;

	sprite = game->map.arr[y][x];
	if (sprite == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr, \
								(x * game->wall.x_size), \
								(y * game->wall.y_size));
	if (sprite == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr, \
								(x * game->floor.x_size), \
								(y * game->floor.y_size));
	if (sprite == COIN)
		mlx_put_image_to_window(game->mlx, game->win, game->coin.ptr, \
								(x * game->coin.x_size), \
								(y * game->coin.y_size));
	if (sprite == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit.ptr, \
								(x * game->exit.x_size), \
								(y * game->exit.y_size));
}

void	put_player_to_window(t_game *game, t_map *map)
{
	mlx_put_image_to_window(game->mlx, game->win, game->plr_img.ptr, \
							(map->plr_x * game->plr_img.x_size), \
							(map->plr_y * game->plr_img.y_size));
}

int	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			put_sprite_to_window(game, x, y);
			x ++;
		}
		y ++;
	}
	put_player_to_window(game, &game->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	init_struct_game(&game);
	game.mlx = mlx_init();
	init_sprites_img(&game);
	init_map(&game, argv[1]);
	check_map(&game, &(game.map), argc, argv);
	game.win = mlx_new_window(game.mlx, game.map.width, game.map.height, \
							"Game's Window");
	mlx_loop_hook(game.mlx, \
				render, \
				&game);
	mlx_hook(game.win, \
			MLX_KEY_PRESS, \
			1L << 0, \
			key_hook, \
			&game);
	mlx_hook(game.win, \
			MLX_DESTROY_NOTIFY, \
			1L << 17, \
			close_game, \
			&game);
	mlx_loop(game.mlx);
	return (0);
}
