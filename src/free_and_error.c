/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amoiseik <amoiseik@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/09 19:13:44 by amoiseik		  #+#	#+#			 */
/*   Updated: 2025/07/11 12:21:54 by amoiseik		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
}

void	free_all_and_exit(t_game *game, int exit_status)
{
	if (game->map.arr)
		ft_free_array(game->map.arr);
	if (game->mlx) 
	{
		if (game->plr_img.ptr)
		{
			mlx_destroy_image(game->mlx, game->plr_front.ptr);
			mlx_destroy_image(game->mlx, game->plr_left.ptr);
			mlx_destroy_image(game->mlx, game->plr_right.ptr);
			mlx_destroy_image(game->mlx, game->plr_back.ptr);
		}
		if (game->wall.ptr)
		{
			mlx_destroy_image(game->mlx, game->wall.ptr);
			mlx_destroy_image(game->mlx, game->floor.ptr);
			mlx_destroy_image(game->mlx, game->coin.ptr);
			mlx_destroy_image(game->mlx, game->exit_opend.ptr);
			mlx_destroy_image(game->mlx, game->exit_closed.ptr);
		}
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		game->mlx = NULL;
	}
	exit(exit_status);
}

void	error_and_exit(t_game	*game, char *error_message)
{
	int	len;

	len = ft_strlen(error_message);
	write(2, error_message, len);
	free_all_and_exit(game, EXIT_FAILURE);
}

int	close_game(t_game *game)
{
	free_all_and_exit(game, EXIT_SUCCESS);
	return (0);
}
