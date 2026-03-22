/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlee <axlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:13:09 by axlee             #+#    #+#             */
/*   Updated: 2026/03/22 19:17:32 by axlee            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "math3d.h"

Vector3	Vector3Add(Vector3 a, Vector3 b)
{
	Vector3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

Vector3	Vector3Sub(Vector3 a, Vector3 b)
{
	Vector3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
}

Vector3	Vector3Multiply(Vector3 a, float scalar)
{
	Vector3	result;

	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	return (result);
}

Vector3	Vector3Divide(Vector3 a, float scalar)
{
	Vector3	result;

	result.x = a.x / scalar;
	result.y = a.y / scalar;
	result.z = a.z / scalar;
	return (result);
}
