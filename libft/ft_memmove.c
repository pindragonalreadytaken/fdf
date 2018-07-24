/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:37:22 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 12:42:43 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (dest < src || (unsigned int)(dest - src) > n)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (d);
}
