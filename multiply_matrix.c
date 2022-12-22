#include "fdf.h"

void	multiply_matrix(t_float3 *in, t_float3 *out, t_mat4x4 * m)
{
	float w;

	out->x = m->m[0][0] * in->x + m->m[0][1] * in->y + m->m[0][2] * in->z + m->m[0][3];
	out->y = m->m[1][0] * in->x + m->m[1][1] * in->y + m->m[1][2] * in->z + m->m[1][3];
	out->z = m->m[2][0] * in->x + m->m[2][1] * in->y + m->m[2][2] * in->z + m->m[2][3];
	w = 	 m->m[3][0] * in->x + m->m[3][1] * in->y + m->m[3][2] * in->z + m->m[3][3];

	// out->x = m->m[0][0] * in->x + m->m[1][0] * in->y + m->m[2][0] * in->z + m->m[3][0];
	// out->y = m->m[0][1] * in->x + m->m[1][1] * in->y + m->m[2][1] * in->z + m->m[3][1];
	// out->z = m->m[0][2] * in->x + m->m[1][2] * in->y + m->m[2][2] * in->z + m->m[3][2];
	// w =		 m->m[0][3] * in->x + m->m[1][3] * in->y + m->m[2][3] * in->z + m->m[3][3];

	if (w != 1.0)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}