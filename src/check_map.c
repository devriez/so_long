/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:13:44 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 16:47:07 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	check_argc(t_game *game, int argc)
{
	if (argc == 1)
		error_and_exit(game, "Error\nNo file name\n");
	if (argc > 2)
		error_and_exit(game, "Error\nToo many arguments in map's path\n");
}

static void	check_cl_args(t_game *game, int argc, char **argv)
{
	char	*extension;
	char	*path;

	check_argc(game, argc);
	extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		error_and_exit(game, "Error\nInvalid extension (must be .ber)\n");
	path = argv[1];
	while (*path != '\0')
	{
		if (!(ft_isalnum(*path) || *path == '-' || *path == '_' || \
										*path == '/' || *path == '.'))
			error_and_exit(game, "Error\nInvalid chars in the file name\n");
		path ++;
	}
}

void	check_map(t_game *game, t_map *map, int argc, char **argv)
{
	int	x;
	int	y;

	check_cl_args(game, argc, argv);
	if (map->exits != 1 || map->players != 1 || map->coins == 0)
		error_and_exit(game, "Error\nInvalid number of sprites\n");
	if (map->invalid_sprites > 0)
		error_and_exit(game, "Error\nInvalid charakters on map\n");
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		if (ft_strlen(map->arr[y]) != map->columns)
			error_and_exit(game, "Error\nMap is not rectangular\n");
		while (x < map->columns)
		{
			if (x == 0 || x == map->columns - 1 || y == 0 || \
				y == map->rows - 1)
				if (map->arr[y][x] != WALL)
					error_and_exit(game, "Error\nDoesn't surrounded with W\n");
			x ++;
		}
		y ++;
	}
	check_valid_path(game, map);
}
