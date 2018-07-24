/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 08:47:14 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 15:02:59 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		click_event(int button, int x, int y, void *param)
{
	t_mlx_env *env;

	env = (t_mlx_env*)param;
	if (x < 0 || x > 1000 || y < 0 || y > 800)
		return (0);
	env->mouse_clicked = 1;
	env->mouse_x = x;
	env->mouse_y = y;
	return (button);
}

int		release_event(int button, int x, int y, void *param)
{
	t_mlx_env	*env;

	env = (t_mlx_env*)param;
	(void)x;
	(void)y;
	env->mouse_clicked = 0;
	return (button);
}

void	find_min_max_heights(t_mlx_env *env)
{
	int		i;
	int		j;
	float	z;
	float	min;
	float	max;

	i = 0;
	while (i < env->map_height)
	{
		j = 0;
		while (j < env->map_width)
		{
			z = env->map[i][j]->z;
			if (z > max || (i == 0 && j == 0))
				max = z;
			else if (z < min || (i == 0 && j == 0))
				min = z;
			j++;
		}
		i++;
	}
	env->min_height = min;
	env->max_height = max;
}

void	launch_mlx(t_mlx_env *env, t_mat44 *cam)
{
	void	*mlx;
	void	*win;
	void	*image;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 800, "FdF");
	image = mlx_new_image(mlx, 1000, 800);
	env->mlx = mlx;
	env->win = win;
	env->cam = cam;
	env->image = image;
	env->mouse_clicked = 0;
	find_min_max_heights(env);
	print_points(env);
	mlx_hook(win, KeyPress, KeyPressMask, process_key_event, env);
	mlx_hook(win, ButtonPress, ButtonPressMask, click_event, env);
	mlx_hook(win, ButtonRelease, ButtonReleaseMask, release_event, env);
	mlx_hook(win, MotionNotify, ButtonMotionMask, motion_event, env);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx_env	*env;
	t_mat44		*camera_matrix;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	if (!(env = (t_mlx_env*)malloc(sizeof(t_mlx_env))))
		return (0);
	initialize_grid(argv[1], env);
	camera_matrix = new_mat44(new_vec4(1, 0, 0, 0)
									, new_vec4(0, 1, 0, 0)
									, new_vec4(0, 0, 1, 0)
									, new_vec4(-env->map_width / 2
										, -env->map_height / 2
										, -env->map_width, 1));
	launch_mlx(env, camera_matrix);
}
