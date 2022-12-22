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

	// matrix->m[0][0] = 1;
	// matrix->m[0][1] = 0;
	// matrix->m[0][2] = 0;
	// matrix->m[0][3] = 0;
	// matrix->m[1][0] = 0;
	// matrix->m[1][1] = 1;
	// matrix->m[1][2] = 0;
	// matrix->m[1][3] = 0;
	// matrix->m[2][0] = 0;
	// matrix->m[2][1] = 0;
	// matrix->m[2][2] = 0;
	// matrix->m[2][3] = 0;
	// matrix->m[3][0] = 0;
	// matrix->m[3][1] = 0;
	// matrix->m[3][2] = 0;
	// matrix->m[3][3] = 1.0f;
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
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotx_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = sin(fTheta);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = -sin(fTheta);
	matrix->m[2][2] = cos(fTheta);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotxy_init(t_mat4x4 *matrix, float fTheta, float fTheta2)
{
	matrix->m[0][0] = cos(fTheta2);
	matrix->m[0][1] = 0;
	matrix->m[0][2] = -sin(fTheta2);
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = sin(fTheta);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = sin(fTheta2);
	matrix->m[2][1] = -sin(fTheta);
	matrix->m[2][2] = cos(fTheta) * cos(fTheta2);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_roty_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][1] = 0;
	matrix->m[0][2] = -sin(fTheta);
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 1;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = sin(fTheta);
	matrix->m[2][1] = 0;
	matrix->m[2][2] = cos(fTheta);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotate_init(t_mat4x4 *matrix, float x, float y, float z)
{
	matrix->m[0][0] = cos(y) * cos(z);
	matrix->m[0][1] = sin(x) * sin(y) * cos(z) - cos(x) * sin(z);
	matrix->m[0][2] = cos(x) * sin(y) * cos(z) + sin(x) * sin(z);
	matrix->m[0][3] = 0;
	matrix->m[1][0] = cos(y) * sin(z);
	matrix->m[1][1] = sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
	matrix->m[1][2] = cos(x) * sin(y) * sin(z) - sin(x) * cos(z);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = -sin(y);
	matrix->m[2][1] = sin(x) * cos(y);
	matrix->m[2][2] = cos(x) * cos(y);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
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
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
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
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;

	// matrix->m[0][0] = 1.0f;
	// matrix->m[0][1] = 0;
	// matrix->m[0][2] = 0;
	// matrix->m[0][3] = 0;
	// matrix->m[1][0] = 0;
	// matrix->m[1][1] = 1.0f;
	// matrix->m[1][2] = 0;
	// matrix->m[1][3] = 0;
	// matrix->m[2][0] = 0;
	// matrix->m[2][1] = 0;
	// matrix->m[2][2] = 1.0f;
	// matrix->m[2][3] = 0;
	// matrix->m[3][0] = x;
	// matrix->m[3][1] = y;
	// matrix->m[3][2] = z;
	// matrix->m[3][3] = 1;
}

void	matrix_iso_init(t_mat4x4 *matrix)
{
	matrix->m[0][0] = 0;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 0;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = 0;
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][3] = 1;
}