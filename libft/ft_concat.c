/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:25:38 by jnaddef           #+#    #+#             */
/*   Updated: 2016/02/16 19:32:59 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(char *s1, char *s2)
{
	char	*conc;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	conc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		conc[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		conc[i] = s2[j];
		i++;
		j++;
	}
	conc[i] = '\0';
	free(s1);
	return (conc);
}
