/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:47:42 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/08 16:54:15 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_mlx_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->map_height)
	{
		j = 0;
		while (j < env->map_width)
		{
			if (i > 0)
				draw_line(env, env->map[i][j], env->map[i - 1][j]);
			if (j > 0)
				draw_line(env, env->map[i][j], env->map[i][j - 1]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
}
