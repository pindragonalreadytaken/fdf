/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:58:54 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 12:21:11 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		calculate_color(t_mlx_env *env, float z)
{
	unsigned char	regulated_z;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				color;

	color = 0;
	regulated_z = (unsigned char)(z - env->min_height)
		* 255 / (env->max_height - env->min_height);
	if (regulated_z >= 0 && regulated_z <= 127)
	{
		green = 255 * (1 - sin((255 - regulated_z * 2) * M_PI / 2 / 255));
		blue = 255 - green;
		red = 0;
	}
	else
	{
		blue = 0;
		red = 255 * sin((regulated_z - 128) * 2 * M_PI / 2 / 255);
		green = 255 - red;
	}
	color = (color & ~(0xFF << (0 * 8))) | blue << (0 * 8);
	color = (color & ~(0xFF << (1 * 8))) | green << (1 * 8);
	color = (color & ~(0xFF << (2 * 8))) | red << (2 * 8);
	return (color);
}
