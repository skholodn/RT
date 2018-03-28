/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:12:06 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/20 17:49:08 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

void			get_cam_info(char **file, t_camera *cam)
{
	if (check_str("pos: ", *file) != -1 && ((*file) += 5))
		get_vec_info(*file, &cam->pos);
	else if (check_str("direction: ", *file) != -1 && ((*file) += 11))
		get_vec_info(*file, &cam->look_point);
	else if (check_str("up: ", *file) != -1 && ((*file) += 4))
		get_vec_info(*file, &cam->look_up);
	else if (check_str("angle: ", *file) != -1 && ((*file) += 7))
		cam->angle = ft_atof(*file);
	skip_it(file, '\n');
}

t_camera		*parse_camera(char **file)
{
	t_camera	*cam;

	cam = (t_camera *)ft_memalloc(sizeof(t_camera));
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t", *file) != -1 && ((*file) += 2))
			get_cam_info(file, cam);
		else
			print_error("Wrong scene data!!!");
	}
	calculate_cam(cam, &cam->look_point, &cam->look_up);
	if (cam->angle >= -360.0f && cam->angle <= 360.0f)
		cam->angle = tanf((float)3.14f * 0.5f * cam->angle / 180.f);
	else
		print_error("Wrong angle for camera");
	return (cam);
}
