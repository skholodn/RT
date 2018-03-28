/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:14:20 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:14:22 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	new_control(t_scene *scene, size_t threads_count)
{
	t_control control;

	if (!scene)
		return ;
	control.quit = 0;
	control.scene = scene;
	control.cur_obj = 0;
	control.pos_cur_obj = &scene->objects[control.cur_obj]->center;
	control.is_camera = 0;
	control.threads = get_threads(threads_count, scene,
								&control.threads_status, &control.run);
	control.redraw = 1;
	main_loop(&control);
}
