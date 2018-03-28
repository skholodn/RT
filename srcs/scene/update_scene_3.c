/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:08:02 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 11:48:36 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	get_color_2(t_vec3 *diff_col, t_vec3 *refr_col,
		t_vec3 *refl_col, t_ray *ray)
{
	diff_col->x *= ray->obj->material->diffuse;
	diff_col->y *= ray->obj->material->diffuse;
	diff_col->z *= ray->obj->material->diffuse;
	refr_col->x *= ray->obj->material->transparency;
	refr_col->y *= ray->obj->material->transparency;
	refr_col->z *= ray->obj->material->transparency;
	refl_col->x *= ray->obj->material->reflectivity;
	refl_col->y *= ray->obj->material->reflectivity;
	refl_col->z *= ray->obj->material->reflectivity;
}

t_vec3	get_color(t_ray *ray, t_scene *scene)
{
	t_vec3	diff_col;
	t_vec3	refr_col;
	t_vec3	refl_col;

	if (trace(ray, scene->objects))
	{
		ray->hit = get_hit(ray);
		ray->hit_normal = ray->obj->norm(ray->obj, &ray->hit);
		if (dot_vec3(ray->dir, ray->hit_normal) > 0)
		{
			ray->hit_normal.x *= -1;
			ray->hit_normal.y *= -1;
			ray->hit_normal.z *= -1;
		}
		diff_col = diffuse(ray, scene);
		refr_col = refraction(ray, scene);
		refl_col = reflection(ray, scene);
		get_color_2(&diff_col, &refr_col, &refl_col, ray);
		return (add_vec3(diff_col, add_vec3(refr_col, refl_col)));
	}
	return (scene->ambient);
}

void	set_norm(t_object *obj)
{
	obj->normal = mul_vec3(sub_vec3(obj->vertexes[1], obj->vertexes[0]),
			sub_vec3(obj->vertexes[2], obj->vertexes[0]));
}

char	set_intersect(t_object *obj, char *type)
{
	if (type)
	{
		if (ft_strcmp(type, "gsphere") == 0)
			return (init_sphere_behavior(obj));
		else if (ft_strcmp(type, "gcone") == 0)
			return (init_cone_behavior(obj));
		else if (ft_strcmp(type, "gcylinder") == 0)
			return (init_cylinder_behavior(obj));
		else if (ft_strcmp(type, "gplane") == 0)
			return (init_plane_behavior(obj));
		else if (ft_strcmp(type, "gdisk") == 0)
			return (init_disk_behavior(obj));
	}
	return (0);
}
