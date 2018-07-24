/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:47:43 by exam              #+#    #+#             */
/*   Updated: 2016/05/17 12:00:03 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	g_tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'
	, '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int		ft_abs(int value)
{
	return ((value < 0) ? -value : value);
}

int		num_len(int value, int base)
{
	int cpt;

	cpt = 0;
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
		cpt++;
	while (value != 0)
	{
		value /= base;
		cpt++;
	}
	return (cpt);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*str;
	int		negative;

	i = 0;
	negative = 0;
	if (value < 0 && base == 10)
		negative = 1;
	if (!(str = malloc(sizeof(char) * (num_len(value, base) + 1))))
		return (NULL);
	if (value == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (value != 0)
	{
		str[i++] = g_tab[ft_abs(value % base)];
		value /= base;
	}
	if (negative)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
