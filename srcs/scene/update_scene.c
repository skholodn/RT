/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:37:14 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 17:24:39 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object	*trace(t_ray *ray, t_object **figures)
{
	t_object *obj;

	ray->obj = 0;
	while (*figures)
	{
		obj = *figures;
		if (obj->intersect(ray, obj, &ray->t))
			ray->obj = obj;
		figures++;
	}
	return (ray->obj);
}

t_vec3		diffuse(t_ray *ray, t_scene *scene)
{
	t_ray		i_ray;
	t_vec3		color;
	t_object	**lights;

	color = scene->ambient;
	i_ray.origin = ray->hit;
	lights = scene->lights;
	while (*lights)
	{
		i_ray.t = lenght_vec3(&(*lights)->center, &i_ray.origin);
		i_ray.dir = get_direction(i_ray.origin, (*lights)->center);
		if (trace(&i_ray,
scene->objects) == 0 || i_ray.obj->material->transparency != 0)
			color = add_vec3(color, combo_light(ray->dir, &i_ray.origin,
&ray->hit_normal, *lights));
		lights++;
	}
	if (!(ray->obj->texture.is_texture) ||
		(ray->obj->type != 1 && ray->obj->type != 3))
		mul_in_vec(&color, &ray->obj->material->color);
	else if (ray->obj->texture.is_texture)
		ray->obj->material->color = get_sphere_texture(ray->obj, &ray->hit);
	mul_in_vec(&color, &ray->obj->material->color);
	return (color);
}

t_vec3		reflection(t_ray *ray, t_scene *scene)
{
	t_ray	ray2;
	t_vec3	nhit;

	if (ray->power * ray->obj->material->reflectivity < ACCURACY)
		return (scene->ambient);
	nhit = ray->obj->norm(ray->obj, &ray->hit);
	ray2.origin = ray->hit;
	ray2.dir = reflect_vec3(&ray->dir, &nhit);
	ray2.power = ray->obj->material->reflectivity * ray->power;
	ray2.t = RAY_LEN;
	return (get_color(&ray2, scene));
}

t_vec3		refraction(t_ray *ray, t_scene *scene)
{
	float	t;
	t_vec3	dir;
	t_ray	ray1;

	t = ray->obj->material->transparency;
	if (t * ray->power < ACCURACY)
		return (scene->ambient);
	dir = refract_vec3(ray->dir, ray->obj->norm(ray->obj, &ray->hit),
ray->obj->material->refract_coef);
	if (dir.x == 0 && dir.y == 0 && dir.z == 0)
		return (scene->ambient);
	ray1.dir = dir;
	ray1.power = t * ray->power;
	ray1.origin = ray->hit;
	ray1.t = RAY_LEN;
	return (get_color(&ray1, scene));
}
