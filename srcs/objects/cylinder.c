/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:27:05 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:30:33 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec3			cylinder_norm(t_object *cylinder, t_vec3 *phit)
{
	t_vec3 vec;

	vec.x = phit->x - cylinder->center.x;
	vec.y = phit->y - cylinder->center.y;
	vec.z = phit->z - cylinder->center.z;
	vec = (sub_vec3(vec, mul_vec3_numb(cylinder->normal,
					dot_vec3(cylinder->normal, vec))));
	normalize_vec3(&vec);
	return (vec);
}

static void		init_intersect_data(float *info, t_object *f, t_ray *r)
{
	t_vec3	delta_p;
	t_vec3	sub;
	t_vec3	delta_sub;

	sub = sub_vec3(r->dir, mul_vec3_numb(f->normal, dot_vec3(r->dir,
					f->normal)));
	delta_p = sub_vec3(r->origin, f->center);
	delta_sub = sub_vec3(delta_p, mul_vec3_numb(f->normal,
				dot_vec3(delta_p, f->normal)));
	info[0] = dot_vec3(sub, sub);
	info[1] = 2 * dot_vec3(sub, delta_sub);
	info[2] = dot_vec3(delta_sub, delta_sub) - f->radius * f->radius;
	info[2] = info[1] * info[1] - 4 * info[0] * info[2];
}

char			cylinder_intersect(t_ray *r, t_object *f, float *t)
{
	float	info[3];
	float	root1;
	float	root2;

	init_intersect_data(info, f, r);
	if (info[2] > 0)
	{
		root1 = (-info[1] - sqrtf(info[2])) / (2 * info[0]);
		root2 = (-info[1] + sqrtf(info[2])) / (2 * info[0]);
		info[2] = (root1 < root2 && root1 > ACCURACY) ? root1 : root2;
		if (info[2] > ACCURACY && info[2] < *t)
		{
			*t = info[2];
			return (1);
		}
	}
	return (0);
}

char			init_cylinder_behavior(t_object *obj)
{
	obj->intersect = cylinder_intersect;
	obj->norm = cylinder_norm;
	return (1);
}
