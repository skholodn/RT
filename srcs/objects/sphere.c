/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:28:33 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:28:35 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec3				sphere_norm(t_object *sphere, t_vec3 *phit)
{
	t_vec3 vec;

	vec.x = phit->x - sphere->center.x;
	vec.y = phit->y - sphere->center.y;
	vec.z = phit->z - sphere->center.z;
	normalize_vec3(&vec);
	return (vec);
}

char				sphere_intersect(t_ray *ray, t_object *sphere, float *t)
{
	float	abc[3];
	t_vec3	dist;
	float	disc;

	abc[0] = dot_vec3(ray->dir, ray->dir);
	dist = sub_vec3(ray->origin, sphere->center);
	abc[1] = 2 * dot_vec3(ray->dir, dist);
	abc[2] = dot_vec3(dist, dist) - (sphere->radius * sphere->radius);
	disc = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (disc < 0)
		return (0);
	disc = sqrtf(disc);
	abc[2] = (-abc[1] + disc) / 2;
	abc[1] = (-abc[1] - disc) / 2;
	if (abc[1] > abc[2])
		abc[1] = abc[2];
	if (abc[1] > ACCURACY && abc[1] < *t)
	{
		*t = abc[1];
		return (1);
	}
	return (0);
}

char				init_sphere_behavior(t_object *obj)
{
	obj->intersect = sphere_intersect;
	obj->norm = sphere_norm;
	return (1);
}
