#include "fdf.h"

void	multiply_matrix(t_float3 *in, t_mat4x4 * m)
{
	float w;

	in->x = m->m[0][0] * in->x + m->m[0][1] * in->y + m->m[0][2] * in->z + m->m[0][3];
	in->y = m->m[1][0] * in->x + m->m[1][1] * in->y + m->m[1][2] * in->z + m->m[1][3];
	in->z = m->m[2][0] * in->x + m->m[2][1] * in->y + m->m[2][2] * in->z + m->m[2][3];
	w = 	m->m[3][0] * in->x + m->m[3][1] * in->y + m->m[3][2] * in->z + m->m[3][3];

	if (w != 0.0)
	{
		in->x /= w;
		in->y /= w;
		in->z /= w;
	}
}