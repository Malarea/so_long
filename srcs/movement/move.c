/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:42:49 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/06 17:52:22 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Cette fonction sert a compter les mouvements 
*/
void	print_and_add_move(t_game *game)
{
	game->play.moves += 1;
	write(1, "\033[2K\rNombre de mouvements: ", 27);
	ft_putnbr_fd(game->play.moves, 1);
}

void	move_up(t_game *game, int x, int y)
{
	game->play.y -= Y;
	y -= Y;
	ft_put_img(game, game->txtrs.play_back, x, y);
	if (game->play.on_coins == 1)
	{
		ft_put_img(game, game->txtrs.coins_open, x, y + Y);
		game->play.on_coins = 0;
	}
	else if (game->play.on_exit == 1)
	{
		ft_put_img(game, game->txtrs.exit, x, y + Y);
		game->play.on_exit = 0;
	}
	else
		ft_put_img(game, game->txtrs.floor, x, y + Y);
	move_c_coins(game, (y / Y), (x / X));
	print_and_add_move(game);
}

void	move_down(t_game *game, int x, int y)
{
	game->play.y += Y;
	y += Y;
	ft_put_img(game, game->txtrs.play_face, x, y);
	if (game->play.on_coins == 1)
	{
		ft_put_img(game, game->txtrs.coins_open, x, y - Y);
		game->play.on_coins = 0;
	}
	else if (game->play.on_exit == 1)
	{
		ft_put_img(game, game->txtrs.exit, x, y - Y);
		game->play.on_exit = 0;
	}
	else
		ft_put_img(game, game->txtrs.floor, x, y - Y);
	move_c_coins(game, (y / Y), (x / X));
	print_and_add_move(game);
}

void	move_right(t_game *game, int x, int y)
{
	game->play.x += X;
	x += X;
	ft_put_img(game, game->txtrs.play_right, x, y);
	if (game->play.on_coins == 1)
	{
		ft_put_img(game, game->txtrs.coins_open, x - X, y);
		game->play.on_coins = 0;
	}
	else if (game->play.on_exit == 1)
	{
		ft_put_img(game, game->txtrs.exit, x - X, y);
		game->play.on_exit = 0;
	}
	else
		ft_put_img(game, game->txtrs.floor, x - X, y);
	move_c_coins(game, (y / Y), (x / X));
	print_and_add_move(game);
}

void	move_left(t_game *game, int x, int y)
{
	game->play.x -= X;
	x -= X;
	ft_put_img(game, game->txtrs.play_left, x, y);
	if (game->play.on_coins == 1)
	{
		ft_put_img(game, game->txtrs.coins_open, x + X, y);
		game->play.on_coins = 0;
	}
	else if (game->play.on_exit == 1)
	{
		ft_put_img(game, game->txtrs.exit, x + X, y);
		game->play.on_exit = 0;
	}
	else
		ft_put_img(game, game->txtrs.floor, x + X, y);
	move_c_coins(game, (y / Y), (x / X));
	print_and_add_move(game);
}
