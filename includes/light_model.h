/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_model.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:16:24 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/27 13:16:28 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_MODEL_H
# define LIGHT_MODEL_H

# define PHONG_COEF 5

# include "uf_math.h"
# include "objects.h"

t_vec3	phong_light(t_vec3 *ray_dir, t_vec3 *to_light_dir,
					t_vec3 *nphit, t_vec3 *light_intensity);
t_vec3	lambert_light(t_vec3 *ray_dir, t_vec3 *nphit, t_vec3 power);
t_vec3	combo_light(t_vec3 r_dir, t_vec3 *hit, t_vec3 *nphit, t_object *light);

#endif
