/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:54:13 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/03 11:29:48 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_to(t_line_inf *inf, float x0, float y0, float z0)
{
	inf->to->x = x0;
	inf->to->y = y0;
	inf->to->z = -1.f;
	inf->to->w = 1.f;
	inf->to_z = z0;
}

void	update_from(t_line_inf *inf, float x0, float y0, float z0)
{
	inf->from->x = x0;
	inf->from->y = y0;
	inf->from->z = -1.f;
	inf->from->w = 1.f;
	inf->from_z = z0;
}

void	check_screen(t_line_inf *inf)
{
	float	x0;
	float	y0;
	float	z0;

	if (inf->from->z > -1.f || inf->to->z > -1.f)
	{
		x0 = inf->from->x - (inf->from->x - inf->to->x)
			* (inf->from->z + 1.f) / (inf->from->z - inf->to->z);
		y0 = inf->from->y - (inf->from->y - inf->to->y)
			* (inf->from->z + 1.f) / (inf->from->z - inf->to->z);
		z0 = inf->from_z - (inf->from_z - inf->to_z)
			* (inf->from->z + 1.f) / (inf->from->z - inf->to->z);
		if (inf->from->z > -1.f)
		{
			update_from(inf, x0, y0, z0);
		}
		else
		{
			update_to(inf, x0, y0, z0);
		}
	}
}
