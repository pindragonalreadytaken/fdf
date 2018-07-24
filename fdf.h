/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 08:47:14 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/03 11:25:44 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include "X.h"
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec4;

typedef struct	s_mat44
{
	t_vec4	*m_i;
	t_vec4	*m_j;
	t_vec4	*m_k;
	t_vec4	*m_o;
}				t_mat44;

typedef struct	s_mlx_env
{
	void		*mlx;
	void		*win;
	t_mat44		*cam;
	t_vec4		***map;
	void		*image;
	int			map_height;
	int			map_width;
	int			mouse_clicked;
	int			mouse_x;
	int			mouse_y;
	float		min_height;
	float		max_height;
}				t_mlx_env;

typedef struct	s_line_inf
{
	t_vec4	*from;
	t_vec4	*to;
	int		from_z;
	int		to_z;
	int		from_x;
	int		to_x;
	int		from_y;
	int		to_y;
}				t_line_inf;

int				motion_event(int x, int y, void *env);
int				process_key_event(int key_code, void *env);
t_mat44			*matrix_matrix_product(const t_mat44 *mat1
		, const t_mat44 *mat2);
t_vec4			*matrix_vector_product(const t_mat44 *mat, const t_vec4 *vec);
void			display_matrix(t_mat44 mat);
void			display_vector(t_vec4 vec);
t_vec4			*new_vec4(float x, float y, float z, float w);
t_mat44			*new_mat44(t_vec4 *i, t_vec4 *j, t_vec4 *k, t_vec4 *o);
void			translate(t_mat44 **mat, t_vec4 *translation);
void			rotate(t_mat44 **mat, t_mat44 *rotation);
void			initialize_grid(char *filename, t_mlx_env *env);
void			clear_points(t_mlx_env *env);
void			print_points(t_mlx_env *env);
void			draw_line(t_mlx_env *env, const t_vec4 *point1
		, const t_vec4 *point2);
void			fill_pixel(void *image, int x, int y, int color);
int				calculate_color(t_mlx_env *env, float z);
void			check_screen(t_line_inf *inf);
void			clear_then_exit(t_mlx_env *env);
void			project_on_screen(t_line_inf *inf);
void			scale_on_screen(t_line_inf *inf);

#endif
