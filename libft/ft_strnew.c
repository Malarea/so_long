/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <emachrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:18:52 by emachrek          #+#    #+#             */
/*   Updated: 2022/03/06 18:03:13 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*string;

	string = ft_memalloc(size + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < size)
		string[i++] = '\0';
	return (string);
}
