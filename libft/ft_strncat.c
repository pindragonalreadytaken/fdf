/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:56:54 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 14:12:17 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	char			*d;

	d = dest;
	i = 0;
	while (*d)
		d++;
	while (src[i] && i < n)
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (dest);
}
