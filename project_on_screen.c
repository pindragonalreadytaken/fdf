/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_on_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <jnaddef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:23:00 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/03 11:27:03 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_on_screen(t_line_inf *inf)
{
	inf->from->x = -1 * inf->from->x / inf->from->z;
	inf->from->y = -1 * inf->from->y / inf->from->z;
	inf->to->x = -1 * inf->to->x / inf->to->z;
	inf->to->y = -1 * inf->to->y / inf->to->z;
}

void	scale_on_screen(t_line_inf *inf)
{
	inf->from_x = (inf->from->x + 1) / 2 * 1000;
	inf->from_y = (inf->from->y + 1) / 2 * 800;
	inf->to_x = (inf->to->x + 1) / 2 * 1000;
	inf->to_y = (inf->to->y + 1) / 2 * 800;
}
