/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:37:39 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/14 15:15:12 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(size * sizeof(*fresh));
	if (fresh == NULL)
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
