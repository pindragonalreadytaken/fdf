/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 08:47:14 by jnaddef           #+#    #+#             */
/*   Updated: 2017/11/02 17:44:28 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat44	*new_mat44(t_vec4 *i, t_vec4 *j, t_vec4 *k, t_vec4 *o)
{
	t_mat44 *new_mat;

	if (!(new_mat = (t_mat44*)malloc(sizeof(t_mat44))))
		exit(0);
	new_mat->m_i = i;
	new_mat->m_j = j;
	new_mat->m_k = k;
	new_mat->m_o = o;
	return (new_mat);
}

t_vec4	*matrix_vector_product(const t_mat44 *mat, const t_vec4 *vec)
{
	t_vec4	*result;

	if (!(result = (t_vec4*)malloc(sizeof(t_vec4))))
		exit(0);
	result->x = vec->x * mat->m_i->x + vec->y * mat->m_j->x
		+ vec->z * mat->m_k->x + vec->w * mat->m_o->x;
	result->y = vec->x * mat->m_i->y + vec->y * mat->m_j->y
		+ vec->z * mat->m_k->y + vec->w * mat->m_o->y;
	result->z = vec->x * mat->m_i->z + vec->y * mat->m_j->z
		+ vec->z * mat->m_k->z + vec->w * mat->m_o->z;
	result->w = vec->x * mat->m_i->w + vec->y * mat->m_j->w
		+ vec->z * mat->m_k->w + vec->w * mat->m_o->w;
	return (result);
}

t_mat44	*matrix_matrix_product(const t_mat44 *mat1, const t_mat44 *mat2)
{
	t_mat44	*result;

	if (!(result = (t_mat44*)malloc(sizeof(t_mat44))))
		exit(0);
	result->m_i = matrix_vector_product(mat1, mat2->m_i);
	result->m_j = matrix_vector_product(mat1, mat2->m_j);
	result->m_k = matrix_vector_product(mat1, mat2->m_k);
	result->m_o = matrix_vector_product(mat1, mat2->m_o);
	return (result);
}

void	translate(t_mat44 **mat, t_vec4 *translation)
{
	t_mat44	*o_mat;
	t_mat44	*mat_translation;

	o_mat = *mat;
	mat_translation = new_mat44(new_vec4(1, 0, 0, 0)
			, new_vec4(0, 1, 0, 0), new_vec4(0, 0, 1, 0), translation);
	*mat = matrix_matrix_product(mat_translation, *mat);
	free((o_mat)->m_i);
	free((o_mat)->m_j);
	free((o_mat)->m_k);
	free((o_mat)->m_o);
	free(o_mat);
	free(mat_translation->m_i);
	free(mat_translation->m_j);
	free(mat_translation->m_k);
	free(mat_translation->m_o);
	free(mat_translation);
}

void	rotate(t_mat44 **mat, t_mat44 *rotation)
{
	t_mat44	*o_mat;

	o_mat = *mat;
	*mat = matrix_matrix_product(rotation, *mat);
	free((o_mat)->m_i);
	free((o_mat)->m_j);
	free((o_mat)->m_k);
	free((o_mat)->m_o);
	free(o_mat);
	free(rotation->m_i);
	free(rotation->m_j);
	free(rotation->m_k);
	free(rotation->m_o);
	free(rotation);
}
