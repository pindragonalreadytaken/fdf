/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:24:53 by jnaddef           #+#    #+#             */
/*   Updated: 2016/04/28 14:04:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void *content)
{
	t_list	*temp;
	t_list	*previous;

	temp = *alst;
	previous = NULL;
	while (temp)
	{
		if (temp->content == content)
		{
			if (previous == NULL)
				*alst = temp->next;
			else
				previous->next = temp->next;
			free(temp->content);
			free(temp);
			temp = NULL;
			return ;
		}
		previous = temp;
		temp = temp->next;
	}
}
