/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:54:32 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 18:55:48 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = (char*)s;
	while (*str)
	{
		if (*str == (char)c)
		{
			tmp = str;
		}
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (tmp);
}
