/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:26:58 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:26:59 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec3			cone_norm(t_object *cylinder, t_vec3 *phit)
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

static void		init_intersect_data(float *i, t_object *f, t_ray *r)
{
	float	cos2;
	float	sin2;
	t_vec3	delta_p;
	t_vec3	sub;
	t_vec3	delta_sub;

	delta_p = sub_vec3(r->origin, f->center);
	i[1] = dot_vec3(r->dir, f->normal);
	cos2 = cosf(f->radius) * cosf(f->radius);
	sin2 = sinf(f->radius) * sinf(f->radius);
	sub = sub_vec3(r->dir, mul_vec3_numb(f->normal, i[1]));
	i[2] = dot_vec3(delta_p, f->normal);
	delta_sub = sub_vec3(delta_p, mul_vec3_numb(f->normal, i[2]));
	i[0] = cos2 * dot_vec3(sub, sub) - sin2 * i[1] * i[1];
	i[1] = 2 * cos2 * dot_vec3(sub, delta_sub) - 2 * sin2 * i[1] * i[2];
	i[2] = cos2 * dot_vec3(delta_sub, delta_sub) - sin2 * i[2] * i[2];
	i[2] = i[1] * i[1] - 4 * i[0] * i[2];
}

char			cone_intersect(t_ray *r, t_object *f, float *t)
{
	float	info[3];
	float	root1;
	float	root2;

	init_intersect_data(info, f, r);
	if (info[2] > 0)
	{
		root1 = (-info[1] - sqrtf(info[2])) / (2 * info[0]);
		root2 = (-info[1] + sqrtf(info[2])) / (2 * info[0]);
		info[2] = root1 < ACCURACY ? root2 : root1;
		if (info[2] > ACCURACY && info[2] < *t)
		{
			*t = info[2];
			return (1);
		}
	}
	return (0);
}

char			init_cone_behavior(t_object *obj)
{
	obj->intersect = cone_intersect;
	obj->norm = cone_norm;
	return (1);
}
