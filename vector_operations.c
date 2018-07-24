/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 08:47:14 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 13:14:31 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	*new_vec4(float x, float y, float z, float w)
{
	t_vec4 *new_vec;

	if (!(new_vec = (t_vec4*)malloc(sizeof(t_vec4))))
		exit(0);
	new_vec->x = x;
	new_vec->y = y;
	new_vec->z = z;
	new_vec->w = w;
	return (new_vec);
}
