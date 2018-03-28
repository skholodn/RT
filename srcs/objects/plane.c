/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:28:14 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:28:15 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec3		plane_norm(t_object *plane, t_vec3 *phit)
{
	phit = 0;
	return (plane->normal);
}

char		plane_intersect(t_ray *ray, t_object *plane, float *t)
{
	float a;
	float b;

	a = dot_vec3(ray->dir, plane->normal);
	if (ABS(a) > ACCURACY)
	{
		b = (dot_vec3(plane->normal, ray->origin) +
			dot_vec3(plane->normal, plane->center)) / a;
		if (-b > ACCURACY && -b <= *t)
		{
			*t = -b;
			return (1);
		}
	}
	return (0);
}

char		init_plane_behavior(t_object *obj)
{
	obj->intersect = plane_intersect;
	obj->norm = plane_norm;
	return (1);
}
