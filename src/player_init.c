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

// void	init_player(t_game *game)
// {
// 	t_player	*player;

// 	player = malloc(sizeof(t_player));
// 	player->left = mlx_xpm_file_to_image(game->mlx, \
// 											PLAYER_LEFT, \
// 											&player->img_width, \
// 											&player->img_hight);
// 	player->right = mlx_xpm_file_to_image(game->mlx, \
// 											PLAYER_RIGHT, \
// 											&player->img_width, \
// 											&player->img_hight);
// 	player->back = mlx_xpm_file_to_image(game->mlx, \
// 											PLAYER_BACK, \
// 											&player->img_width, \
// 											&player->img_hight);
// 	player->front = mlx_xpm_file_to_image(game->mlx, \
// 											PLAYER_FRONT, \
// 											&player->img_width, \
// 											&player->img_hight);
// 	player->image = player->front;
// 	player->x = 0;
// 	player->y = 0;
// 	game->player = player;
// }

// void	destroy_player(t_game *game, t_player *player)
// {
// 	mlx_destroy_image(game->mlx, player->back);
// 	mlx_destroy_image(game->mlx, player->front);
// 	mlx_destroy_image(game->mlx, player->left);
// 	mlx_destroy_image(game->mlx, player->right);
// 	free(player);
// }
