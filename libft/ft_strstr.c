/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:14:16 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/13 17:01:04 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hs, const char *needle)
{
	int		i;
	int		j;
	char	*haystack;

	haystack = (char*)hs;
	i = 0;
	j = 0;
	while (haystack[i])
	{
		if (!needle[j])
			return (haystack + i);
		if (haystack[i + j] == needle[j])
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	if (!needle[j])
		return (haystack + i);
	return (NULL);
}
