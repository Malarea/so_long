/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:53 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/06 17:52:53 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
Cette fonction sert a initialiser toutes les conditions requises
*/

void	ft_init(t_game *game, char *file)
{
	game->map.map = ft_get_map(file);
	game->map.y_max = ft_map_ymax(game->map.map);
	game->map.x_max = ft_map_xmax(game->map.map);
	game->map.rect = ft_check_rect(game->map.map, game->map.y_max);
	game->map.charset = ft_check_char(game->map.map);
	game->map.walls = ft_check_walls(game->map.map, game->map.y_max);
	game->map.exit = 0;
	game->map.coins = 0;
	game->map.player = 0;
	game->play.coins = 0;
	game->play.on_coins = 0;
	game->play.on_exit = 0;
	game->play.moves = 0;
	ft_check_exit_coins_start(game);
}

/*
Cette fonction sert a initialiser les textures pour notre jeu
*/
void	ft_init_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	img_height = Y;
	img_width = X;
	game->txtrs.play_face = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/char_face.xpm", &img_width, &img_height);
	game->txtrs.play_back = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/char_back.xpm", &img_width, &img_height);
	game->txtrs.play_right = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/char_right.xpm", &img_width, &img_height);
	game->txtrs.play_left = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/char_left.xpm", &img_width, &img_height);
	game->txtrs.wall = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/wall.xpm", &img_width, &img_height);
	game->txtrs.floor = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/floor.xpm", &img_width, &img_height);
	game->txtrs.coins = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/coins.xpm", &img_width, &img_height);
	game->txtrs.coins_open = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/coins_used.xpm", &img_width, &img_height);
	game->txtrs.exit = mlx_xpm_file_to_image(game->mlx,
			"srcs/init/textures/exit.xpm", &img_width, &img_height);
}
