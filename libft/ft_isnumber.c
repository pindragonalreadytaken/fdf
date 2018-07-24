/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:02:30 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/02 14:30:35 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(char *str)
{
	int	i;
	int	rep;
	int	nb;

	nb = 0;
	rep = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '0')
			rep = 1;
		if (rep)
			nb++;
		i++;
	}
	return (nb);
}

int			ft_isnumber(char *str)
{
	int		i;
	int		is_number;
	long	value;
	int		digit_nb;

	is_number = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		is_number = 1;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	digit_nb = count_digits(str);
	if (digit_nb > 10)
		return (0);
	value = ft_atoi_long(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (is_number);
}
