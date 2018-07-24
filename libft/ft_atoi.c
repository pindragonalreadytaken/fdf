/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:26:16 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/14 15:47:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(nptr[i]))
	{
		if (!nptr[i])
			return (0);
		i++;
	}
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + sign * (nptr[i++] - '0');
	}
	return (num);
}
