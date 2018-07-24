/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:46:59 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/18 12:47:53 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char(char const *s, char c)
{
	char	*str;
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	while (str[i] == c)
	{
		i++;
	}
	if (i == j + 1)
		return (ft_strnew(0));
	while (str[j] == c)
	{
		j--;
	}
	trimmed = ft_substring(str, i, j);
	return (trimmed);
}
