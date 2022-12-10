#include "fdf.h"

// void	translate_vector(t_float3 *vector, float x, float y, float z)
// {
// 	t_matrix4x4 matrix = {
// 	{1.0, 0.0, 0.0, x},
// 	{0.0, 1.0, 0.0, y},
// 	{0.0, 0.0, 1.0, z},
// 	{0.0, 0.0, 0.0, 1.0}
// 	};

// 	vector->x = vector->x * matrix.a[1] + vector->x * matrix.a[2] + vector->x * matrix.a[3] + vector->x * matrix.a[4]
// 	vector->y = vector->y * matrix.b[1] + vector->y * matrix.b[2] + vector->y * matrix.b[3] + vector->y * matrix.b[4]
// 	vector->z = vector->z * matrix.c[1] + vector->z * matrix.c[2] + vector->z * matrix.c[3] + vector->z * matrix.c[4]
// 	vector->w = vector->w * matrix.d[1] + vector->w * matrix.d[2] + vector->w * matrix.d[3] + vector->w * matrix.d[4]

// }