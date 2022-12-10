#include "fdf.h"

void	multiply_matrix(t_float3 *in, t_float3 *out, t_mat4x4 * m)
{
	float w;

	out->x = in->x * m->m[0][0] + in->y * m->m[1][0] + in->z * m->m[2][0] + m->m[3][0];
	out->y = in->x * m->m[0][1] + in->y * m->m[1][1] + in->z * m->m[2][1] + m->m[3][1];
	out->z = in->x * m->m[0][2] + in->y * m->m[1][2] + in->z * m->m[2][2] + m->m[3][2];
	w = in->x * m->m[0][3] + in->y * m->m[1][3] + in->z * m->m[2][3] + m->m[3][3];

	if (w != 0.0)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}