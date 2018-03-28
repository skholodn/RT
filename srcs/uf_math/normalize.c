/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:55:12 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:55:13 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

inline void	normalize_vec3(t_vec3 *v)
{
	float len;

	len = (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
	if (len > 0)
	{
		len = 1.f / len;
		v->x *= len;
		v->y *= len;
		v->z *= len;
	}
}
