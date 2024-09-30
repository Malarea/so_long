/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:10:01 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/08 13:56:00 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Cette fonction sert a verifier si toutes les conditions requises sont presentes
*/
int	ft_check_struc(t_game *game)
{
	int	result;

	result = 0;
	if (!game->map.map[0])
		ft_putstr("Error\nAucune map.\n");
	else if (!game->map.rect)
		ft_putstr("Error\nLa map n'est pas rectangle.\n");
	else if (!game->map.charset)
		ft_putstr("Error\nLa map contient un/des caractères inconnu(s).\n");
	else if (!game->map.walls)
		ft_putstr("Error\nLa map a un probleme de mur.\n");
	else if (!game->map.exit)
		ft_putstr("Error\nLa map doit contenir 1 sortie.\n");
	else if (!game->map.coins)
		ft_putstr("Error\nLa map ne possède aucun collectible.\n");
	else if (game->map.player < 1)
		ft_putstr("Error\nLa map doit contenir 1 joueur.\n");
	else
		result = 1;
	return (result);
}
