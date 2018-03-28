/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:30:34 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:30:40 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static inline void	resize_arr(t_object ***arr, size_t last_len, size_t new_len)
{
	t_object	**new_arr;
	size_t		i;

	new_arr = (t_object**)malloc(sizeof(t_object*) * (new_len + 1));
	i = -1;
	while (++i < last_len)
		new_arr[i] = (*arr)[i];
	free(*arr);
	*arr = new_arr;
}

char				add_object(t_scene *scene, t_object *obj)
{
	if (obj)
	{
		if (scene->last_obj == scene->obj_count)
			resize_arr(&scene->objects, scene->last_obj,
					scene->obj_count + STANDART_OBJECT_COUNT);
		scene->objects[scene->last_obj] = obj;
		scene->last_obj++;
		scene->objects[scene->last_obj] = 0;
		return (1);
	}
	return (0);
}

char				add_light(t_scene *scene, t_object *obj)
{
	if (obj)
	{
		if (scene->last_light == scene->light_count)
			resize_arr(&scene->lights, scene->last_light,
					scene->light_count + STANDART_LIGHT_COUNT);
		scene->lights[scene->last_light] = obj;
		scene->last_light++;
		scene->lights[scene->last_light] = 0;
		return (1);
	}
	return (0);
}
