/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:28:54 by amoiseik          #+#    #+#             */
/*   Updated: 2025/07/10 16:50:56 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER_BACK  "assets/sprites/player/back.xpm"
# define PLAYER_FRONT "assets/sprites/player/front.xpm"
# define PLAYER_LEFT  "assets/sprites/player/left.xpm"
# define PLAYER_RIGHT "assets/sprites/player/right.xpm"
# define COIN_PATH "assets/sprites/coin-bag.xpm"
# define EXIT_CLOSED "assets/sprites/exit-closed.xpm"
# define EXIT_OPENED "assets/sprites/exit-opened.xpm"
# define FLOOR "assets/sprites/floor.xpm"
# define WALL "assets/sprites/wall.xpm"

# define WALL				'1'
# define FLOOR 				'0'
# define COIN  				'C'
# define PLAYER				'P'
# define EXIT 			 	'E'

#define HEIGHT 500
#define WIDTH 500
#define MLX_KEY_PRESS 2   // Event code for a key being pressed
#define MLX_DESTROY_NOTIFY 17  // Event code for window close button (red X)

// --- X11 Event Masks (Common for Linux) ---
// These masks tell the X server which events we are interested in.
#define MLX_KEY_PRESS_MASK        (1L << 0) // Mask for KeyPress events
#define MLX_STRUCTURE_NOTIFY_MASK (1L << 17) // Mask for window destruction events

// --- Colors ---
#define COLOR_BLACK         0x000000FF // Black color (background)

// --- MLX Sync Commands (for smooth rendering) ---
#define MLX_SYNC_IMAGE_WRITABLE     1 // Indicates image is ready for writing
#define MLX_SYNC_IMG_TO_WIN_CMD      2 // Command to push changes to the window

#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

#define UP_KEY 65362
#define LEFT_KEY 65361
#define DOWN_KEY 65364
#define RIGHT_KEY 65363

#define ESQ_KEY 65307

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_image
{
	void	*ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char **arr;

	int	plr_x;
	int	plr_y;

	int	coins;
	int	exits;
	int	players;
	int	invalid_sprites;

	int	rows;
	int	columns;
	
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int		movements;

	t_map		map;

	t_image		wall;
	t_image		floor;
	t_image		coin;
	t_image		exit_opend;
	t_image		exit_closed;

	t_image		plr_current_img;
	t_image		plr_front;
	t_image		plr_left;
	t_image		plr_right;
	t_image		plr_back;
}	t_game;


// Функции BFS для валидации пути
// Структура для хранения координат (для очереди)
typedef struct s_coord {
    int x;
    int y;
} t_coord;

// Структура для хранения состояния BFS
typedef struct s_bfs_state {
    t_coord *queue;         // Очередь для BFS (динамически выделенная)
    int     head;           // Указатель на начало очереди
    int     tail;           // Указатель на конец очереди
    int     *visited;       // Двумерный массив посещенных клеток (одномерный для простоты)
    int     found_collectibles; // Количество найденных собираемых предметов
    int     exit_reachable; // Флаг, указывающий, достижим ли выход
} t_bfs_state;

#include <stdlib.h>// For malloc
#include <stdio.h> //!!!!!!!!! printf
#include <fcntl.h>    // open
#include <unistd.h> //write, read, close
#include "mlx.h"
#include "libft.h"

void	init_player(t_game *game);
int		player_move(int keycode, t_game *game);

void 	map_init(t_game *game, char *map_path);
void	check_argc(int argc);
void	check_cl_arguments(int argc, char **argv);
void	is_path_in_map(t_map *map);


//free
void	error_and_exit(char *error_message);

//utils
char	*get_next_line(int fd);
char	*ft_strappend(char **s1, const char *s2)

#endif