/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:11 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:14:12 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

static inline char		add_val(float *v, int val)
{
	*v += val;
	return (1);
}

char					move(t_control *control, SDL_Scancode *key)
{
	if (*key == SDL_SCANCODE_LEFT)
		return (add_val(&control->pos_cur_obj->x, -10));
	if (*key == SDL_SCANCODE_RIGHT)
		return (add_val(&control->pos_cur_obj->x, 10));
	if (*key == SDL_SCANCODE_UP)
		return (add_val(&control->pos_cur_obj->y, 10));
	if (*key == SDL_SCANCODE_DOWN)
		return (add_val(&control->pos_cur_obj->y, -10));
	if (*key == SDL_SCANCODE_1)
		return (add_val(&control->pos_cur_obj->z, 10));
	if (*key == SDL_SCANCODE_2)
		return (add_val(&control->pos_cur_obj->z, -10));
	return (0);
}
