/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:12:24 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:18:23 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	next_obj(t_control *control)
{
	control->cur_obj++;
	if (control->cur_obj >= control->scene->last_obj)
		control->cur_obj = 0;
	control->pos_cur_obj = &control->scene->objects[control->cur_obj]->center;
}
