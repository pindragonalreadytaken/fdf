/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_key_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 08:47:14 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 15:20:49 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mlx_env *env, double angle, int sign)
{
	rotate(&((t_mlx_env*)env)->cam, new_mat44(
			new_vec4(1, 0, 0, 0)
			, new_vec4(0, cos(angle * sign), sin(angle * sign), 0)
			, new_vec4(0, -sin(angle * sign), cos(angle * sign), 0)
			, new_vec4(0, 0, 0, 1)));
}

void	rotate_y(t_mlx_env *env, double angle, int sign)
{
	rotate(&((t_mlx_env*)env)->cam, new_mat44(
			new_vec4(cos(angle * sign), 0, -sin(angle * sign), 0)
			, new_vec4(0, 1, 0, 0)
			, new_vec4(sin(angle * sign), 0, cos(angle * sign), 0)
			, new_vec4(0, 0, 0, 1)));
}

int		process_key_event(int key_code, void *env)
{
	if (key_code == 53)
		clear_then_exit((t_mlx_env*)env);
	if (key_code == 0)
		translate(&((t_mlx_env*)env)->cam, new_vec4(2, 0, 0, 1));
	if (key_code == 2)
		translate(&((t_mlx_env*)env)->cam, new_vec4(-2, 0, 0, 1));
	if (key_code == 1)
		translate(&((t_mlx_env*)env)->cam, new_vec4(0, 0, -2, 1));
	if (key_code == 13)
		translate(&((t_mlx_env*)env)->cam, new_vec4(0, 0, 2, 1));
	if (key_code == 34)
		rotate_x(env, 0.1, 1);
	if (key_code == 40)
		rotate_x(env, 0.1, -1);
	if (key_code == 38)
		rotate_y(env, 0.1, -1);
	if (key_code == 37)
		rotate_y(env, 0.1, 1);
	clear_points(env);
	print_points(env);
	return (0);
}

void	process_motion(t_mlx_env *env, int x, int y)
{
	int		dx;
	int		dy;
	float	angle_x;
	float	angle_y;

	if (env->mouse_clicked == 0)
		return ;
	dy = x - env->mouse_x;
	dx = y - env->mouse_y;
	env->mouse_x = x;
	env->mouse_y = y;
	angle_x = -0.1 * dx / 50;
	angle_y = +0.1 * dy / 50;
	rotate_x(env, angle_x, 1);
	rotate_y(env, angle_y, 1);
	clear_points(env);
	print_points(env);
}

int		motion_event(int x, int y, void *env)
{
	process_motion(env, x, y);
	return (0);
}
