/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:43:06 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 19:45:07 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

t_vec3	refract_vec3(t_vec3 dir, t_vec3 normal, float refract_coef)
{
	float dir_norm;
	float a;
	float d;
	float b;
	float bf;

	dir_norm = dot_vec3(dir, normal);
	if (dir_norm > 0)
	{
		dir_norm = -dir_norm;
		bf = 1;
		a = refract_coef;
	}
	else
	{
		a = 1 / refract_coef;
		bf = -1;
	}
	d = 1 - a * a * (1 - dir_norm * dir_norm);
	if (d < 0)
		return (new_vec3(0, 0, 0));
	b = bf * (dir_norm * a + sqrtf(d));
	return (new_vec3(a * dir.x + b * normal.x, a * dir.y + b * normal.y,
	a * dir.z + b * normal.z));
}
