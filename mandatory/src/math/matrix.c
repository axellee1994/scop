/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlee <axlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:12:19 by axlee             #+#    #+#             */
/*   Updated: 2026/03/22 19:17:42 by axlee            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "math3d.h"

Matrix	MatrixIdentity(void)
{
	Matrix	result;

	result = (Matrix){0};
	result.m[0] = 1.0f;
	result.m[5] = 1.0f;
	result.m[10] = 1.0f;
	result.m[15] = 1.0f;
	return (result);
}

Matrix	MatrixMultiply(Matrix a, Matrix b)
{
	Matrix	result;
	int		row;
	int		col;

	result = (Matrix){0};
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.m[row * 4 + col] = a.m[row * 4 + 0] * b.m[0 * 4 + col]
				+ a.m[row * 4 + 1] * b.m[1 * 4 + col] + a.m[row * 4 + 2] * b.m[2
				* 4 + col] + a.m[row * 4 + 3] * b.m[3 * 4 + col];
			col++;
		}
		row++;
	}
	return (result);
}

// Returns row and column of the matrix
Matrix	MatrixTranslate(float x, float y, float z)
{
	Matrix	result;

	result = MatrixIdentity();
	result.m03 = x;
	result.m13 = y;
	result.m23 = z;
	return (result);
}

Matrix	MatrixRotateY(float angle)
{
	Matrix	result;
	float	radians;
	float	cosA;
	float	sinA;

	result = MatrixIdentity();
	radians = angle * (M_PI / 180.0f);
	cosA = cosf(radians);
	sinA = sinf(radians);
	result.m00 = cosA;
	result.m02 = sinA;
	result.m20 = -sinA;
	result.m22 = cosA;
	return (result);
}

Matrix	MatrixPerspective(float fov, float aspect, float nearPlane,
		float farPlane)
{
	Matrix	result;
	float	f;

	result = (Matrix){0};
	f = 1.0f / tanf(fov * (M_PI / 360.0f));
	result.m00 = f / aspect;
	result.m11 = f;
	result.m22 = (farPlane + nearPlane) / (nearPlane - farPlane);
	result.m23 = (2.0f * farPlane * nearPlane) / (nearPlane - farPlane);
	result.m32 = -1.0f;
	return (result);
}
