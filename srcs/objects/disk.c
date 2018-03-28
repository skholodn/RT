/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:35:31 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:35:45 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static char		disk_intersect(t_ray *ray, t_object *f, float *t)
{
	t_vec3	hitpoint;
	t_vec3	v;

	if (plane_intersect(ray, f, t))
	{
		hitpoint = get_hit(ray);
		v = sub_vec3(hitpoint, f->center);
		if (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z) < f->radius)
			return (1);
	}
	return (0);
}

static t_vec3	disk_norm(t_object *disk, t_vec3 *phit)
{
	phit = 0;
	return (disk->normal);
}

char			init_disk_behavior(t_object *obj)
{
	obj->intersect = disk_intersect;
	obj->norm = disk_norm;
	return (1);
}

t_object		*new_disk(t_vec3 center, t_vec3 normal,
						float radius, t_material *material)
{
	t_object *obj;

	obj = (t_object *)malloc(sizeof(t_object));
	obj->center = center;
	obj->radius = radius;
	obj->normal = normal;
	obj->intersect = disk_intersect;
	obj->norm = disk_norm;
	obj->material = material;
	return (obj);
}
