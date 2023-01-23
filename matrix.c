#include "fdf.h"

void	multiply_with_matrix(t_float3 *in, t_float3 *out, t_mat4x4 * m)
{
	float w;

	out->x = m->m[0][0] * in->x + m->m[0][1] * in->y + m->m[0][2] * in->z + m->m[0][3];
	out->y = m->m[1][0] * in->x + m->m[1][1] * in->y + m->m[1][2] * in->z + m->m[1][3];
	out->z = m->m[2][0] * in->x + m->m[2][1] * in->y + m->m[2][2] * in->z + m->m[2][3];
	w = 	 m->m[3][0] * in->x + m->m[3][1] * in->y + m->m[3][2] * in->z + m->m[3][3];

	if (w != 1.0 && w != 0)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}

void		zero_matrix4x4(t_mat4x4 *matrix)
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
			matrix->m[i][j++] = 0;
		i++;
	}
}

t_mat4x4	multiply_matrices(t_mat4x4 *first, t_mat4x4 *second)
{
	int i;
	int j;
	t_mat4x4 rtn;

	zero_matrix4x4(&rtn);
	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{  
			rtn.m[i][j] = first->m[i][0] * second->m[0][j] +
						  first->m[i][1] * second->m[1][j] +
						  first->m[i][2] * second->m[2][j] +
						  first->m[i][3] * second->m[3][j];
			j++;
		}
		i++;
	}
	return (rtn);
}


