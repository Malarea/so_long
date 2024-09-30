/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:17 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/06 19:26:29 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Cette fonction sert a afficher un image en utilisant la lib mlx
*/
void	ft_put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y);
}

/*
Cette fonction sert a afficher chaque textures(coins,wall,floors,players)
*/
void	ft_print_texts(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map.map[i])
	{
		j = -1;
		while (game.map.map[i][++j])
		{
			if (game.map.map[i][j] == 'E')
				ft_put_img(&game, game.txtrs.exit, j * X, i * Y);
			else if (game.map.map[i][j] == '1')
				ft_put_img(&game, game.txtrs.wall, j * X, i * Y);
			else if (game.map.map[i][j] == '0' || game.map.map[i][j] == 'P')
				ft_put_img(&game, game.txtrs.floor, j * X, i * Y);
			else if (game.map.map[i][j] == 'C')
				ft_put_img(&game, game.txtrs.coins, j * X, i * Y);
			if (j == game.play.x / X && i == game.play.y / Y)
			{
				ft_put_img(&game, game.txtrs.floor, j * X, i * Y);
				ft_put_img(&game, game.txtrs.play_face, j * X, i * Y);
			}
		}
		i++;
	}
}
