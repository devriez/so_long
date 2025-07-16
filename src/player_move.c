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
#include "mlx.h"

int	player_move(int keycode, t_game *game)
{
	if(keycode == S_KEY || keycode == DOWN_KEY)
	{
		game->player->ptr = game->player->front;
		game->player->y += 50;
	}
	if(keycode == W_KEY || keycode == UP_KEY)
	{
		game->player->ptr = game->player->back;
		game->player->y -= 50;
	}
	if(keycode == A_KEY || keycode == LEFT_KEY)
	{
		game->player->ptr = game->player->left;
		game->player->x -= 50;
	}
	if(keycode == D_KEY || keycode == RIGHT_KEY)
	{
		game->player->ptr = game->player->right;
		game->player->x += 50;
	}
	return (0);
}
