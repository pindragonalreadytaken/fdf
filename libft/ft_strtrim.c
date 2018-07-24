/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:52:09 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/18 18:28:11 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
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
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		i++;
	}
	if (i == j + 1)
		return (ft_strnew(0));
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
	{
		j--;
	}
	trimmed = ft_substring(str, i, j);
	return (trimmed);
}
