/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:12:18 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/02 16:13:02 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	t_list	*temp;
	int		cpt;

	temp = list;
	cpt = 0;
	while (temp)
	{
		cpt++;
		temp = temp->next;
	}
	return (cpt);
}
