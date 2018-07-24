/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:57:30 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/20 15:35:04 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh_list;
	t_list	*temp;
	t_list	*next;
	t_list	*temp_fresh;

	if (lst == NULL)
		return (NULL);
	fresh_list = (t_list*)malloc(sizeof(t_list));
	if (fresh_list == NULL)
		return (NULL);
	temp = lst;
	fresh_list = ft_memcpy(fresh_list, (*f)(temp), sizeof(t_list));
	temp = temp->next;
	temp_fresh = fresh_list;
	while (temp)
	{
		next = (t_list*)malloc(sizeof(t_list));
		if (next == NULL)
			return (NULL);
		next = ft_memcpy(next, (*f)(temp), sizeof(t_list));
		temp = temp->next;
		temp_fresh->next = next;
		temp_fresh = temp_fresh->next;
	}
	return (fresh_list);
}
