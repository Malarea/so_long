/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:04:07 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/07 16:36:18 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"
# include "../minilibx/mlx.h"

# define MOVE_UP 13
# define MOVE_DOWN 1
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define ESC 53

# define X 64
# define Y 64

typedef struct s_map
{
	char	**map;
	size_t	y_max;
	size_t	x_max;
	size_t	coins;
	size_t	player;
	size_t	exit;
	size_t	walls;
	size_t	rect;
	size_t	charset;
}	t_map;

typedef struct s_textures
{
	void	*play_face;
	void	*play_back;
	void	*play_right;
	void	*play_left;
	void	*wall;
	void	*floor;
	void	*coins;
	void	*coins_open;
	void	*exit;
}	t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	size_t	coins;
	int		on_coins;
	int		on_exit;
	size_t	moves;
}	t_player;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_textures	txtrs;
	t_map		map;
	t_player	play;
}	t_game;

/*=============================================*/
/*                 INIT GAME                   */
/*=============================================*/

void	ft_init(t_game *game, char *file);
void	ft_init_textures(t_game *game);

/*=============================================*/
/*                 PARSE MAP                   */
/*=============================================*/

char	**ft_get_map(char *file);
int		ft_map_ymax(char **map);
int		ft_map_xmax(char **map);

/*=============================================*/
/*                   CHECKS                    */
/*=============================================*/

int		ft_check_rect(char **map, int nb_l);
int		ft_check_char(char **map);
int		ft_check_walls(char **map, int nb_l);
int		ft_check_exit_coins_start(t_game *game);
int		ft_check_struc(t_game *game);

/*=============================================*/
/*               PRINT TEXTURES                */
/*=============================================*/

void	ft_put_img(t_game *game, void *img_ptr, int x, int y);
void	ft_print_texts(t_game game);

/*=============================================*/
/*                  MOVEMENT                   */
/*=============================================*/

int		key_hook(int keycode, t_game *game);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);
int		move_c_is(char c, t_game *game, int y, int x);
int		move_c_exit(t_game *game);
int		move_c_coins(t_game *game, int y, int x);

/*=============================================*/
/*               FREE END GAME                */
/*=============================================*/
int		ft_close(t_game *game);
void	ft_free_map(char **map);

#endif
