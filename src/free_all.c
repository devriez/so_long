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

void	free_all(t_game	*game)
{
	if (game->plr_current_img.ptr)
	{
		mlx_destroy_image(game->mlx, game->plr_current_img.ptr);
		
	}
}

void	error_and_exit(char *error_message)
{
	int	len;

	len = ft_strlen(error_message);
	write(2, error_message, len);
	exit(EXIT_FAILURE);
	//добавить освобождение всего!!!!!!!
}

void free_map(t_map *map)
{
	free(map->arr);
	free(map);
}

void free_game(t_game *game)
{
	
}