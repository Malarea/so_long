/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:41:12 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:30 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_c_is(char c, t_game *game, int y, int x)
{
	return (game->map.map[y][x] == c);
}

int	move_c_exit(t_game *game)
{
	if (game->play.coins == game->map.coins)
	{
		ft_putstr("\n=============== SO_LONG ===============\n");
		ft_putstr("            Partie terminée\n");
		write(1, "               Score: ", 23);
		ft_putnbr_fd(game->play.coins, 1);
		write(1, "\n", 1);
		ft_putstr("=======================================\n");
		ft_close(game);
	}
	return (0);
}

int	move_c_coins(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == 'C')
	{
		game->map.map[y][x] = 'O';
		game->play.coins += 1;
		game->play.on_coins = 1;
		return (1);
	}
	if (game->map.map[y][x] == 'E')
	{
		game->play.on_exit = 1;
		move_c_exit(game);
		return (1);
	}
	if (game->map.map[y][x] == 'O')
	{
		game->play.on_coins = 1;
		return (1);
	}
	return (0);
}
