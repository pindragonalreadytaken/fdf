/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:47:11 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/19 15:55:31 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dest;
	i = 0;
	s = (const unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
