/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:02:00 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/19 18:18:18 by jnaddef          ###   ########.fr       */
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

static int	count_words(char *str, char c)
{
	int	previous_space;
	int	i;
	int cpt;

	i = 0;
	cpt = 0;
	previous_space = 1;
	while (str[i])
	{
		if (str[i] == c)
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

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*str;
	int		nb_words;

	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	nb_words = count_words(str, c);
	split = (char**)malloc(sizeof(char*) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	split = split_words(split, str, ft_strlen(s));
	return (split);
}
