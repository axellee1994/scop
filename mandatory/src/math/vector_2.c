/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlee <axlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:13:23 by axlee             #+#    #+#             */
/*   Updated: 2026/03/22 19:13:26 by axlee            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "math3d.h"

float	Vector3Dot(Vector3 a, Vector3 b)
{
	Vector3	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result.x + result.y + result.z);
}

Vector3	Vector3CrossProduct(Vector3 a, Vector3 b)
{
	Vector3	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}
