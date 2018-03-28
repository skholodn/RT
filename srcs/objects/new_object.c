/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:40:40 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:40:50 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*new_object(void)
{
	t_object *obj;

	obj = (t_object *)ft_memalloc(sizeof(t_object));
	obj->material = new_material();
	return (obj);
}
