/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:05:34 by jnaddef           #+#    #+#             */
/*   Updated: 2018/07/23 17:09:34 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_points(t_line_inf *inf)
{
	t_vec4	*temp;
	int		temp_z;

	temp = inf->from;
	inf->from = inf->to;
	inf->to = temp;
	temp_z = inf->from_z;
	inf->from_z = inf->to_z;
	inf->to_z = temp_z;
}

void	draw_case1(t_mlx_env *env, t_line_inf *inf)
{
	int	temp_x;
	int	temp_y;
	int	z;
	int	color;

	if (inf->from->x > inf->to->x)
		swap_points(inf);
	scale_on_screen(inf);
	temp_x = inf->from_x;
	while (temp_x <= inf->to_x)
	{
		if (inf->to_x != inf->from_x)
		{
			z = inf->from_z + ((inf->to_z - inf->from_z)
					* (temp_x - inf->from_x)) / (inf->to_x - inf->from_x);
			color = calculate_color(env, z);
			temp_y = inf->from_y + ((inf->to_y - inf->from_y)
					* (temp_x - inf->from_x)) / (inf->to_x - inf->from_x);
			if (temp_x > 0 && temp_x < 1000 && temp_y > 0 && temp_y < 800)
				fill_pixel(env->image, temp_x, temp_y, color);
		}
		temp_x++;
	}
}

void	draw_case2(t_mlx_env *env, t_line_inf *inf)
{
	int	temp_x;
	int	temp_y;
	int	z;
	int	color;

	if (inf->from->y > inf->to->y)
		swap_points(inf);
	scale_on_screen(inf);
	temp_y = inf->from_y;
	while (temp_y <= inf->to_y)
	{
		if (inf->to_y != inf->from_y)
		{
			z = inf->from_z + ((inf->to_z - inf->from_z)
					* (temp_y - inf->from_y)) / (inf->to_y - inf->from_y);
			color = calculate_color(env, z);
			temp_x = inf->from_x + ((inf->to_x - inf->from_x)
					* (temp_y - inf->from_y)) / (inf->to_y - inf->from_y);
			if (temp_x > 0 && temp_x < 1000 && temp_y > 0 && temp_y < 800)
				fill_pixel(env->image, temp_x, temp_y, color);
		}
		temp_y++;
	}
}

void	draw_line(t_mlx_env *env, const t_vec4 *o_point1
		, const t_vec4 *o_point2)
{
	t_vec4		*point1;
	t_vec4		*point2;
	t_line_inf	*inf;
	// Still github, user pindragon42

	point1 = matrix_vector_product(env->cam, o_point1);
	point2 = matrix_vector_product(env->cam, o_point2);
	if (!(point1->z > -1.f && point2->z > -1.f))
	{
		if (!(inf = malloc(sizeof(t_line_inf))))
			exit(-1);
		inf->from = point1;
		inf->to = point2;
		inf->from_z = o_point1->z;
		inf->to_z = o_point2->z;
		check_screen(inf);
		project_on_screen(inf);
		if (fabs(inf->from->x - inf->to->x) > fabs(inf->from->y - inf->to->y))
			draw_case1(env, inf);
		else
			draw_case2(env, inf);
		free(inf);
	}
	free(point1);
	free(point2);
}
