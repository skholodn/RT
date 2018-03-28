/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:18:52 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:18:56 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_model.h"

inline t_vec3	combo_light(t_vec3 r_dir, t_vec3 *hit, t_vec3 *nphit,
							t_object *light)
{
	t_vec3 to_light_dir;
	t_vec3 phong;
	t_vec3 lambert;

	to_light_dir.x = hit->x - light->center.x;
	to_light_dir.y = hit->y - light->center.y;
	to_light_dir.z = hit->z - light->center.z;
	normalize_vec3(&to_light_dir);
	phong = phong_light(&r_dir, &to_light_dir, nphit, &light->material->color);
	lambert = lambert_light(&to_light_dir, nphit, light->material->color);
	return (add_vec3(phong, lambert));
}
