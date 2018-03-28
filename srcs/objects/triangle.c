/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:59:25 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 18:59:34 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

char		init_inters(t_triangle_intersect *ti, t_object *triangle,
						t_ray *ray)
{
	ti->e1 = sub_vec3(triangle->vertexes[1], triangle->vertexes[0]);
	ti->e2 = sub_vec3(triangle->vertexes[2], triangle->vertexes[0]);
	ti->pvec = mul_vec3(ray->dir, ti->e2);
	ti->det = dot_vec3(ti->e1, ti->pvec);
	if (ti->det < 1e-8 && ti->det > -1e-8)
		return (0);
	ti->det = 1 / ti->det;
	ti->tvec = sub_vec3(ray->origin, triangle->vertexes[0]);
	ti->u = dot_vec3(ti->tvec, ti->pvec) * ti->det;
	if (ti->u < 0 || ti->u > 1)
		return (0);
	ti->qvec = mul_vec3(ti->tvec, ti->e1);
	ti->v = dot_vec3(ray->dir, ti->qvec) * ti->det;
	return (1);
}

char		triangle_intersect(t_ray *ray, t_object *triangle, float *t)
{
	t_triangle_intersect ti;

	if (!init_inters(&ti, triangle, ray))
		return (0);
	if (ti.v < 0 || ti.u + ti.v > 1)
		return (0);
	ti.v = dot_vec3(ti.e2, ti.qvec) * ti.det;
	if (ti.v > ACCURACY && ti.v < *t)
	{
		*t = ti.v;
		return (1);
	}
	return (0);
}
