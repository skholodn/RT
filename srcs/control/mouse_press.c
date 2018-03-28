/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:12:09 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:09:46 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int		mouse_press(Uint8 key, float x, float y, t_control *control)
{
	x = 0;
	y = 0;
	if (key == SDL_BUTTON_LEFT)
	{
		if (control->is_camera)
		{
			control->is_look_point_move = 1;
			control->pos_cur_obj = &control->scene->camera->look_point;
		}
	}
	return (0);
}
