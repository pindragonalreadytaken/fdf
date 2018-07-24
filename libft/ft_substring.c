/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:07:12 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/18 18:55:13 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substring(char *str, int start, int end)
{
	char	*substring;
	int		i;

	i = 0;
	substring = (char*)malloc(sizeof(char) * (end - start + 2));
	if (substring == NULL)
		return (NULL);
	while (i < end - start + 1)
	{
		substring[i] = str[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
