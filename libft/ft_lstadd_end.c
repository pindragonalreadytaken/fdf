/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:13:07 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/18 16:29:18 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list	*temp;

	temp = alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}
