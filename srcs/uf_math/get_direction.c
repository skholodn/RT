/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:51:51 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:51:51 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

inline t_vec3			get_direction(t_vec3 start, t_vec3 dest)
{
	t_vec3 v;

	v.x = dest.x - start.x;
	v.y = dest.y - start.y;
	v.z = dest.z - start.z;
	normalize_vec3(&v);
	return (v);
}
