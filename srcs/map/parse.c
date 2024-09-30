/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:37:06 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/07 16:37:40 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Cette fonction sert a afficher les messages d'erreurs
*/
int	ft_error(int n)
{
	if (n == 0)
	{
		ft_putstr("Error\nLe fichier doit être un fichier.\n");
		exit (0);
	}
	else if (n == 1)
	{
		ft_putstr("Error\nLe fichier est introuvable.\n");
		exit (0);
	}
	return (n);
}

/*
Cette fonction sert a lire le fichier map
*/
char	**ft_get_map(char *file)
{
	char	**map;
	char	*map_line;
	char	buffer[1];
	int		i;
	int		fd;

	i = 0;
	if (open(file, O_RDONLY | O_DIRECTORY) > 0)
		ft_error(0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	while (read(fd, buffer, 1) > 0)
		i++;
	close(fd);
	map_line = malloc(sizeof(char) * i + 1);
	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, buffer, 1))
		map_line[i++] = buffer[0];
	map_line[i] = 0;
	map = ft_split(map_line, '\n');
	free(map_line);
	return (map);
}

int	ft_map_ymax(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_map_xmax(char **map)
{
	int	i;

	i = 0;
	if (!map[0])
		return (0);
	while (map[0][i])
		i++;
	return (i);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
