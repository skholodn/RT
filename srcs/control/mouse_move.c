/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:11:14 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:11:21 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <control.h>

int			mouse_move(int x, int y, t_control *control)
{
	if (control->is_look_point_move && x < control->scene->window->width &&
		y > 0 && y < control->scene->window->height && control->pos_cur_obj)
	{
		control->pos_cur_obj->x = x - (control->scene->window->width / 2);
		control->pos_cur_obj->y = -(y - (control->scene->window->height / 2));
		control->pos_cur_obj->z = 0;
		camera_update(control->scene->camera);
		control->redraw = 1;
	}
	return (0);
}
