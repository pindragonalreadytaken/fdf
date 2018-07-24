/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:07:18 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 12:41:04 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char*)dest;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
