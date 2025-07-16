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

#include "mlx.h"
#include "so_long.h"


int	key_hook(int keycode, t_game *game)
{
	player_move(keycode, game);

	if (keycode == ESQ_KEY)
	{
		free_all();
		//destroy_player(game, game->player);
		// mlx_destroy_image(game->mlx, game->bg);
		// mlx_destroy_window(game->mlx, game->win);
		// mlx_destroy_display(game->mlx);
		// exit(0);
	}
	return (0);
}

int	render(t_game *game)
{

	// mlx_put_image_to_window(game->mlx, \
	// 						game->win, \
	// 						game->player->image, \
	// 						game->player->x, \
	// 						game->player->y);
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;


	game.mlx = mlx_init();
	check_cl_arguments(argc, argv);    //need to test
	init_map(&game, argv[1]);          //need to test
	check_map(game.map);               //write and test
	init_sprites_img(&game);           //возможно перенести в init_map
	init_player(&game);                // need to test
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Game's window");


	mlx_loop_hook(game.mlx, 
					render, 
					&game);

	mlx_hook(game.win, \
			MLX_KEY_PRESS, \
			1L << 0, \
			key_hook, \
			&game);
	mlx_loop(game.mlx);

	return (0);
}
