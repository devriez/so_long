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

void	check_argc(int argc)
{
		if (argc == 1)
			error_and_exit("No file name\n");
		if (argc > 2)
			error_and_exit("Too many arguments in map's path\n");
}

void	check_cl_arguments(int argc, char **argv)
{
	char	**path_splited;
	char	*extension;
	char	*path;

	check_argc(argc);
	path_splited = ft_split(argv[1], '.');
	path = path_splited[0];
	extension = path_splited[1];
	if(path_splited[2] || extension == NULL || \
		ft_strncmp(extension, "ber", ft_strlen(extension) + 1) != 0)
		{
			free(path_splited);
			error_and_exit("Invalid file name\n");
		}
	while(*path != '\0')
	{
		if(!(ft_isalpha(*path) ||  *path == '-' || *path == '_'))
		{
			free(path_splited);
			error_and_exit("Invalid file name\n");
		}
		path ++;
	}
}

void	check_map(t_map *map)
{
	int	x;
	int	y;

	if (map->exits > 1 || map->exits == 0 || map->players > 1 || 
		map->exits == 0 || map->coins == 0)
		error_and_exit("Invalid number of coins / player / exits");
	if(map->invalid_sprites > 0)
		error_and_exit("Invalid charakters on map");
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x <  map->columns)
		{
			if (x == 0 || x == map->columns - 1 || y == 0 || \
				y == map->rows - 1)
			{
				if (map->arr[x][y] != WALL)
					error_and_exit("Map doesn't surrounded with walls");
			}
			x ++;
		}
		if(ft_strlen(map->arr[y]) != map->rows)
			error_and_exit("Map is not rectangular");
		y ++;
	}
	is_path_in_map(map);
}
