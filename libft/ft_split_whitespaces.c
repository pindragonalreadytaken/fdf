/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:43:11 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 18:00:53 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_words(char **split, char *str, int len)
{
	int	cpt;
	int i;

	i = 0;
	cpt = 0;
	while (i < len)
	{
		if (str[i])
		{
			split[cpt] = ft_strdup(&(str[i]));
			if (split[cpt] == NULL)
				return (NULL);
			while (str[i])
				i++;
			cpt++;
		}
		else
		{
			i++;
		}
	}
	split[cpt] = NULL;
	return (split);
}

static int	count_words(char *str)
{
	int	previous_space;
	int	i;
	int cpt;

	i = 0;
	cpt = 0;
	previous_space = 1;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			previous_space = 1;
			str[i] = '\0';
		}
		else if (previous_space)
		{
			previous_space = 0;
			cpt++;
		}
		i++;
	}
	return (cpt);
}

char		**ft_split_whitespaces(char const *s)
{
	char	**split;
	char	*str;
	int		nb_words;

	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	nb_words = count_words(str);
	split = (char**)malloc(sizeof(char*) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	split = split_words(split, str, ft_strlen(s));
	free(str);
	return (split);
}
