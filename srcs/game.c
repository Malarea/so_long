/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:06:09 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/07 16:43:12 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Fonction qui sert a detruire(fermer) le jeu
*/
int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->txtrs.coins);
	mlx_destroy_image(game->mlx, game->txtrs.coins_open);
	mlx_destroy_image(game->mlx, game->txtrs.exit);
	mlx_destroy_image(game->mlx, game->txtrs.floor);
	mlx_destroy_image(game->mlx, game->txtrs.play_back);
	mlx_destroy_image(game->mlx, game->txtrs.play_face);
	mlx_destroy_image(game->mlx, game->txtrs.play_left);
	mlx_destroy_image(game->mlx, game->txtrs.play_right);
	mlx_destroy_image(game->mlx, game->txtrs.wall);
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game->map.map);
	exit(0);
}

/*
Fonction qui sert a capturer la touche sur laquelle on appuie
*/
int	ft_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->play.x;
	y = game->play.y;
	if (keycode == ESC)
		ft_close(game);
	if (keycode == MOVE_UP && !move_c_is('1', game, ((y - Y) / Y), (x / X)))
		move_up(game, x, y);
	if (keycode == MOVE_DOWN && !move_c_is('1', game, ((y + Y) / Y), (x / X)))
		move_down(game, x, y);
	if (keycode == MOVE_RIGHT && !move_c_is('1', game, (y / Y), ((x + X) / X)))
		move_right(game, x, y);
	if (keycode == MOVE_LEFT && !move_c_is('1', game, (y / Y), ((x - X) / X)))
		move_left(game, x, y);
	return (0);
}

/*
Fonction qui sert a check l'extension de la map
*/
int	ft_check(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4)
		if (ft_strncmp(&file[len - 4], ".ber", 4) == 0)
			return (1);
	ft_putstr("Error\nLe fichier de map doit appartenir a l'extension .ber\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putstr("Error\nSyntax: ./so_long <map>\n"));
	if (!ft_check(argv[1]))
		return (0);
	ft_init(&game, argv[1]);
	if (!ft_check_struc(&game))
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.map.x_max * X),
			(game.map.y_max * Y), "so_long");
	ft_init_textures(&game);
	ft_print_texts(game);
	mlx_hook(game.win, 2, 1L << 2, ft_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_loop(game.mlx);
	ft_close(&game);
	return (0);
}
