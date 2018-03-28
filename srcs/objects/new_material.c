/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:22:33 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 18:23:18 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_material	*new_material(void)
{
	t_material *material;

	if ((material = (t_material *)malloc(sizeof(t_material))))
	{
		material->name = 0;
		material->color = new_vec3(1.f, 1.f, 1.f);
		material->diffuse = 1;
		material->reflectivity = 0;
		material->refract_coef = 1;
		material->transparency = 0;
	}
	return (material);
}
