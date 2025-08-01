/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 17:11:38 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	player_img_change(int keycode, t_game *game)
{
	if (keycode == S_KEY || keycode == DOWN_KEY)
		game->plr_img = game->plr_front;
	if (keycode == W_KEY || keycode == UP_KEY)
		game->plr_img = game->plr_back;
	if (keycode == A_KEY || keycode == LEFT_KEY)
		game->plr_img = game->plr_left;
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		game->plr_img = game->plr_right;
}

void	player_xy_change(int keycode, t_game *game, t_map *map)
{
	int	x_step;
	int	y_step;

	x_step = 0;
	y_step = 0;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		y_step = 1;
	if (keycode == W_KEY || keycode == UP_KEY)
		y_step = -1;
	if (keycode == A_KEY || keycode == LEFT_KEY)
		x_step = -1;
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		x_step = 1;
	if (map->plr_x + x_step > 0 && map->plr_x + x_step < map->columns -1 && \
		map->arr[map->plr_y][map->plr_x + x_step] != WALL && x_step != 0)
	{
		game->movements ++;
		map->plr_x = map->plr_x + x_step;
	}
	if (map->plr_y + y_step > 0 && map->plr_y + y_step < map->rows - 1 && \
		map->arr[map->plr_y + y_step][map->plr_x] != WALL && y_step != 0)
	{
		game->movements ++;
		map->plr_y = map->plr_y + y_step;
	}
}

void	sprites_change(t_game *game, t_map *map)
{
	if (map->arr[map->plr_y][map->plr_x] == COIN)
	{
		map->coins --;
		map->arr[map->plr_y][map->plr_x] = FLOOR;
	}
	if (map->coins == 0)
		game->exit = game->exit_opend;
}

void	write_movements_num(t_game *game)
{
	char	*movement_num;

	movement_num = ft_itoa(game->movements);
	write(1, "Number of movements = ", 22);
	write(1, movement_num, ft_strlen(movement_num));
	write(1, "\n", 1);
	free(movement_num);
}
