#include "fdf.h"

void	matrix_proj_init(t_mat4x4 *matrix)
{
	matrix->m[0][0] = fAspectRatio * fFovRad;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = fFovRad;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = fFar / (fFar - fNear);
	matrix->m[2][3] = 1.0f;
	matrix->m[3][0] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][2] = (-fFar *fNear) / (fFar - fNear);
	matrix->m[3][3] = 0.0f;
}

void	matrix_orth_proj_init(t_mat4x4 *matrix)
{
	matrix->m[0][0] = 2 / Right - Left;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = 2 / Top - Bottom;
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = 2 / fFar - fNear;
	matrix->m[2][3] = 0;
	matrix->m[3][0] = -(Right + Left / Right - Left);
	matrix->m[3][1] = -(Top + Bottom / Top - Bottom);
	matrix->m[3][2] = -(fFar + fNear / fFar - fNear);
	matrix->m[3][3] = 1.0f;
}

void	matrix_rotz_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = cos(fTheta);
	matrix->m[0][1] = sin(fTheta);
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = -sinf(fTheta);
	matrix->m[1][1] = cos(fTheta);
	matrix->m[1][2] = 0;
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = 0;
	matrix->m[2][2] = 1.0f;
	matrix->m[2][3] = 1.0f;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}

void	matrix_rotx_init(t_mat4x4 *matrix, float fTheta)
{
	matrix->m[0][0] = 1.0f;
	matrix->m[0][1] = 0;
	matrix->m[0][2] = 0;
	matrix->m[0][3] = 0;
	matrix->m[1][0] = 0;
	matrix->m[1][1] = cos(fTheta * 0.5f);
	matrix->m[1][2] = sin(fTheta * 0.5f);
	matrix->m[1][3] = 0;
	matrix->m[2][0] = 0;
	matrix->m[2][1] = -sinf(fTheta * 0.5f);
	matrix->m[2][2] = cos(fTheta * 0.5f);
	matrix->m[2][3] = 0;
	matrix->m[3][0] = 0;
	matrix->m[3][2] = 0;
	matrix->m[3][1] = 0;
	matrix->m[3][3] = 1;
}