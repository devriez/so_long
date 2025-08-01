/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_and_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 16:49:54 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->movements = 0;
	game->wall.ptr = NULL;
	game->floor.ptr = NULL;
	game->coin.ptr = NULL;
	game->exit.ptr = NULL;
	game->exit_opend.ptr = NULL;
	game->exit_closed.ptr = NULL;
	game->plr_img.ptr = NULL;
	game->plr_front.ptr = NULL;
	game->plr_left.ptr = NULL;
	game->plr_right.ptr = NULL;
	game->plr_back.ptr = NULL;
	game->map.arr = NULL;
	game->map.plr_x = 0;
	game->map.plr_y = 0;
	game->map.coins = 0;
	game->map.exits = 0;
	game->map.players = 0;
	game->map.invalid_sprites = 0;
	game->map.rows = 0;
	game->map.columns = 0;
}

static t_image	init_sprite(t_game *game, char *path_to_file)
{
	t_image	sprite;

	sprite.ptr = mlx_xpm_file_to_image(game->mlx, \
										path_to_file, \
										&sprite.x_size, \
										&sprite.y_size);
	if (!sprite.ptr)
		error_and_exit(game, "Error loading sprite image.");
	return (sprite);
}

void	init_sprites_img(t_game *game)
{
	game->plr_front = init_sprite(game, PLAYER_FRONT_XPM);
	game->plr_back = init_sprite(game, PLAYER_BACK_XPM);
	game->plr_left = init_sprite(game, PLAYER_LEFT_XPM);
	game->plr_right = init_sprite(game, PLAYER_RIGHT_XPM);
	game->plr_img = game->plr_front;
	game->coin = init_sprite(game, COIN_PATH_XPM);
	game->exit_closed = init_sprite(game, EXIT_CLOSED_XPM);
	game->exit_opend = init_sprite(game, EXIT_OPENED_XPM);
	game->exit = game->exit_closed;
	game->floor = init_sprite(game, FLOOR_XPM);
	game->wall = init_sprite(game, WALL_XPM);
}
