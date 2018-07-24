/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:26:31 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/20 15:33:40 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ne, size_t n)
{
	unsigned int	j;
	unsigned int	i;
	char			*haystack;
	char			*needle;

	if (n == 0)
		return (NULL);
	j = 0;
	i = 0;
	haystack = (char*)hs;
	needle = (char*)ne;
	while (haystack[i] && needle[j] && i + j < n)
	{
		if (haystack[i + j] == needle[j])
			j++;
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
