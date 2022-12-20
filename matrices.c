#include "fdf.h"

void	matrix_proj_init(t_mat4x4 *matrix)
{
	matrix->m[0][0] = AspectRatio * FovRad;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = FovRad;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = Far / (Far - Near);
	matrix->m[2][3] = 1.0f;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = (-Far *Near) / (Far - Near);
	matrix->m[3][3] = 0.0f;
}

void	matrix_orth_proj_init(t_mat4x4 *matrix)
{
	matrix->m[0][0] = 2 / Right - Left;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = - Right + Left / Right - Left;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 2 / Top - Bottom;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = - Top + Bottom / Top - Bottom;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = - 2 / Far  - Near;
	matrix->m[2][3] = - Far + Near / Far - Near;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1.0f;
}

void	matrix_rotz_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][1] = -sin(fTheta);
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = sin(fTheta);
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = 1.0f;
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_roty_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = -sin(fTheta);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = sin(fTheta);
	matrix->m[2][2] = cos(fTheta);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotx_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][1] = 0;
	matrix->m[0][2] = sin(fTheta);
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 1;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = -sin(fTheta);
	matrix->m[2][2] = cos(fTheta);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotate_init(t_mat4x4 *matrix, float a, float b, float y)
{
	matrix->m[0][0] = cos(a) * cos(b);
	matrix->m[0][1] = cos(a) * sin(b) * sin(y) - sin(a) * cos(y);
	matrix->m[0][2] = cos(a) * sin(b) * cos(y) + sin(a) * sin(y);
	matrix->m[0][3] = 0;
	matrix->m[1][0] = sin(a) * cos(b);
	matrix->m[1][1] = sin(a) * sin(b) * sin(y) + cos(a) * cos(y);
	matrix->m[1][2] = sin(a) * sin(b) * cos(y) - cos(a) * sin(y);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = -sin(b);
	matrix->m[2][1] = cos(b) * sin(y);
	matrix->m[2][2] = cos(b) * cos(y);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_scale_init(t_mat4x4 *matrix,float x)
{
	matrix->m[0][0] = x;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = x;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = x;
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_translate_init(t_mat4x4 *matrix, float x, float y, float z)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = x;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 1.0f;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = y;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = 1.0f;
	matrix->m[2][3] = z;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}