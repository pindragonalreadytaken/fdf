/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 08:29:43 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/08 16:32:39 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_nb_cols(int *nb_cols, char *line)
{
	char	**points;
	int		cpt;

	points = ft_split_whitespaces(line);
	cpt = 0;
	while (points[cpt])
	{
		free(points[cpt]);
		cpt++;
	}
	if (*nb_cols == 0)
		*nb_cols = cpt;
	else if (*nb_cols != cpt)
	{
		ft_putstr("ERROR : Columns number not the same for all lines\n");
		exit(-1);
	}
	free(points);
	free(line);
}

t_vec4	***create_grid(int nb_lines, int nb_cols)
{
	t_vec4	***map;
	int		i;

	if (!(map = malloc(sizeof(t_vec4 **) * (nb_lines + 1))))
		exit(0);
	i = 0;
	while (i < nb_lines)
	{
		if (!(map[i] = malloc(sizeof(t_vec4 *) * (nb_cols + 1))))
			exit(-1);
		i++;
	}
	return (map);
}

void	fill_grid(t_vec4 ***map, char *line, int line_nb)
{
	char	**points;
	int		i;

	points = ft_split_whitespaces(line);
	i = 0;
	while (points[i])
	{
		if (!ft_isnumber(points[i]))
		{
			free(line);
			ft_putstr("ERROR : Invalid format\n");
			exit(-1);
		}
		map[line_nb][i] = new_vec4(i, line_nb, ft_atoi(points[i]), 1);
		free(points[i]);
		i++;
	}
	free(line);
	free(points);
}

void	initialize_grid(char *filename, t_mlx_env *env)
{
	int			fd;
	char		*line;
	int			nb_lines;
	int			nb_cols;
	int			ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(-1);
	nb_lines = 0;
	nb_cols = 0;
	while ((ret = get_next_line(fd, &line)) && ++nb_lines)
	{
		if (ret != 1)
			exit(-1);
		check_nb_cols(&nb_cols, line);
	}
	env->map = create_grid(nb_lines, nb_cols);
	close(fd);
	fd = open(filename, O_RDONLY);
	nb_lines = -1;
	while (get_next_line(fd, &line) && ++nb_lines != -1)
		fill_grid(env->map, line, nb_lines);
	env->map_height = nb_lines + 1;
	env->map_width = nb_cols;
}
