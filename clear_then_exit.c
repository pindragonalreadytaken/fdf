/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_then_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:20:13 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/08 16:32:48 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_then_exit(t_mlx_env *env)
{
	int	i;
	int	j;

	mlx_destroy_window(env->mlx, env->win);
	i = 0;
	while (i < env->map_height)
	{
		j = 0;
		while (j < env->map_width)
		{
			free(env->map[i][j]);
			j++;
		}
		free(env->map[i]);
		i++;
	}
	free(env->map);
	mlx_destroy_image(env->mlx, env->image);
	free(env->cam->m_i);
	free(env->cam->m_j);
	free(env->cam->m_k);
	free(env->cam->m_o);
	free(env->cam);
	free(env);
	exit(0);
}
