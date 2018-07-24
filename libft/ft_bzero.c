/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:37:53 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 12:43:00 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		str[i++] = 0;
	}
}
