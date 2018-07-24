/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:15:39 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 13:03:55 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_image_data(void *image)
{
	int		bpp;
	int		line_size;
	int		endian;

	return (mlx_get_data_addr(image, &bpp, &line_size, &endian));
}

void	fill_pixel(void *image, int x, int y, int color)
{
	int		i;
	int		color_n;
	int		j;
	char	*image_chars;

	image_chars = get_image_data(image);
	j = 0;
	i = 4 * x + 4 * 1000 * y;
	while (j < 4)
	{
		color_n = (color >> (8 * j)) & 0xff;
		image_chars[i] = color_n;
		++j;
		++i;
	}
}
