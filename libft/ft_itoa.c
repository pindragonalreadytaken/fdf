/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:17:32 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/20 15:34:29 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	cpt;
	int	negative;

	negative = 0;
	cpt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		negative = 1;
	while (n != 0)
	{
		n /= 10;
		cpt++;
	}
	return (negative + cpt);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		i;

	i = 0;
	negative = 0;
	str = (char*)malloc((count_digits(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		negative = 1;
	else if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	if (negative)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
