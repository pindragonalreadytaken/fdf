/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:25 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 14:38:00 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	initial_length;

	i = 0;
	initial_length = ft_strlen(dest);
	if (size <= initial_length)
		return (size + ft_strlen(src));
	while (src[i] && i < size - initial_length - 1)
	{
		dest[i + initial_length] = src[i];
		i++;
	}
	dest[i + initial_length] = '\0';
	return (initial_length + ft_strlen(src));
}
