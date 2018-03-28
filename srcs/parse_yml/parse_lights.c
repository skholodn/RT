/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:16:45 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 10:10:46 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

void	get_light_info(char **file, t_object *light, t_scene *scene)
{
	light = (t_object *)ft_memalloc(sizeof(t_object));
	if (check_str("pos: ", *file) != -1 && ((*file) += 5))
		get_vec_info(*file, &light->center);
	else
		print_error("Wrong light position info");
	skip_it(file, '\n');
	light->material = (t_material *)ft_memalloc(sizeof(t_material));
	**file == '#' ? skip_it(file, '\n') : 0;
	if (check_str("\t\t\tpower: ", *file) != -1 && ((*file) += 10))
		get_vec_info(*file, &light->material->color);
	else
		print_error("Wrong light power info");
	skip_it(file, '\n');
	add_light(scene, light);
}

void	get_lights_info(char **file, t_scene *scene)
{
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t\t", *file) != -1 && ((*file) += 3))
			get_light_info(file, NULL, scene);
		else if (check_str("\t\t- light:\n", *file) != -1)
			break ;
		else
			print_error("Wrong light data!!!");
	}
}

void	parse_lights(char **file, t_scene *scene)
{
	scene->lights = (t_object **)ft_memalloc(sizeof(t_object *)
			* (STANDART_LIGHT_COUNT + 1));
	scene->last_light = 0;
	scene->light_count = STANDART_LIGHT_COUNT;
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t- light:\n", *file) != -1 && ((*file) += 11))
			get_lights_info(file, scene);
		else
			print_error("Wrong lights data!!!");
	}
}
