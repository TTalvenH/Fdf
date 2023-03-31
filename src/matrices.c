/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:51 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:54 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_rotz_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][1] = -sin(fTheta);
	matrix->m[1][0] = sin(fTheta);
	matrix->m[1][1] = cos(fTheta);
	matrix->m[2][2] = 1.0f;
	matrix->m[3][3] = 1.0f;
}

void	matrix_rotx_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = sin(fTheta);
	matrix->m[2][1] = -sin(fTheta);
	matrix->m[2][2] = cos(fTheta);
	matrix->m[3][3] = 1;
}

void	matrix_roty_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][2] = -sin(fTheta);
	matrix->m[1][1] = 1;
	matrix->m[2][0] = sin(fTheta);
	matrix->m[2][2] = cos(fTheta);
	matrix->m[3][3] = 1;
}

void	matrix_scale_init(t_mat4x4 *matrix, float x)
{
	matrix->m[0][0] = x;
	matrix->m[1][1] = x;
	matrix->m[2][2] = x;
	matrix->m[3][3] = 1;
}

void	matrix_translate_init(t_mat4x4 *matrix, float x, float y, float z)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[0][3] = x;
	matrix->m[1][1] = 1.0f;
	matrix->m[1][3] = y;
	matrix->m[2][2] = 1.0f;
	matrix->m[2][3] = z;
	matrix->m[3][3] = 1;
}
