/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:48:41 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 14:53:05 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_points(t_mlx_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < 800)
	{
		j = 0;
		while (j < 1000)
		{
			fill_pixel(env->image, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}
