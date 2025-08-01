/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:28:54 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 17:03:52 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> 	// For malloc
# include <fcntl.h>     // open
# include <unistd.h> 	//write, read, close
# include "mlx.h"		//mlx lib
# include "libft.h"		//libgt lib

# define PLAYER_BACK_XPM 	"assets/sprites/player/back.xpm"
# define PLAYER_FRONT_XPM 	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM 	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM 	"assets/sprites/player/right.xpm"
# define COIN_PATH_XPM 		"assets/sprites/coin.xpm"
# define EXIT_CLOSED_XPM 	"assets/sprites/exit-closed.xpm"
# define EXIT_OPENED_XPM 	"assets/sprites/exit-opened.xpm"
# define FLOOR_XPM 			"assets/sprites/floor.xpm"
# define WALL_XPM 			"assets/sprites/wall.xpm"

# define WALL 				49  // ASCII '1'
# define FLOOR 				48  // ASCII '0'
# define COIN 				67  // ASCII 'C'
# define PLAYER 			80  // ASCII 'P'
# define EXIT 				69  // ASCII 'E'

# define W_KEY 				119
# define A_KEY 				97
# define S_KEY 				115
# define D_KEY 				100

# define UP_KEY 			65362
# define LEFT_KEY 			65361
# define DOWN_KEY 			65364
# define RIGHT_KEY 			65363

# define ESQ_KEY 			65307

# define MLX_KEY_PRESS 		2   // Event code for a key being pressed
# define MLX_DESTROY_NOTIFY 17  // Event code for window close button

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_image
{
	void	*ptr;
	int		x_size;
	int		y_size;
}	t_image;

typedef struct s_map
{
	char	**arr;

	int		plr_x;
	int		plr_y;

	int		coins;
	int		exits;
	int		players;
	int		invalid_sprites;

	int		rows;
	int		columns;

	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			movements;

	t_map		map;

	t_image		wall;
	t_image		floor;
	t_image		coin;
	t_image		exit;
	t_image		exit_opend;
	t_image		exit_closed;

	t_image		plr_img;
	t_image		plr_front;
	t_image		plr_left;
	t_image		plr_right;
	t_image		plr_back;
}	t_game;

//Structures for BFS algoritm, validate the path in tha game
typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_bfs_state {
	t_coord	*queue;
	int		head;
	int		tail;
	int		*visited;
	int		found_collectibles;
	int		exit_reachable;
}	t_bfs_state;

//player move
void	player_img_change(int keycode, t_game *game);
void	player_xy_change(int keycode, t_game *game, t_map *map);
void	sprites_change(t_game *game, t_map *map);
void	write_movements_num(t_game *game);

//init map
void	init_map(t_game *game, char *map_path);

//init game and sprites
void	init_sprites_img(t_game *game);
void	init_struct_game(t_game *game);

//check_map
void	check_map(t_game *game, t_map *map, int argc, char **argv);
void	check_valid_path(t_game *g, t_map *m);

//free and exit
void	free_all_and_exit(t_game *game, int exit_status);
void	error_and_exit(t_game	*game, char *error_message);
int		close_game(t_game *game);

//utils
char	*get_next_line(int fd);
char	*ft_strappend(char *s1, const char *s2);

#endif