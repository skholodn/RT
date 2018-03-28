/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:22:04 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 10:09:19 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

void		get_obj_type(char *file, int *type)
{
	if (check_str("sphere", file) == 1)
		*type = 1;
	else if (check_str("plane", file) == 1)
		*type = 2;
	else if (check_str("cylinder", file) == 1)
		*type = 3;
	else if (check_str("cone", file) == 1)
		*type = 4;
	else if (check_str("triangle", file) == 1)
		*type = 5;
	else if (check_str("disc", file) == 1)
		*type = 6;
	else
		print_error("Wrong object type");
}

t_material	get_material_info(char **file)
{
	t_material material;

	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#' && skip_it(file, '\n'))
			continue;
		else if (check_str("\t\t\t\t", *file) == 1)
			(*file) += 4;
		else if (check_str("\t\t\t", *file) == 1)
			break ;
		if (check_str("color: ", *file) != -1 && ((*file) += 7))
			get_vec_info(*file, &material.color);
		else if (check_str("transparency: ", *file) != -1 && ((*file) += 14))
			material.transparency = ft_atoi(*file);
		else if (check_str("reflectivity: ", *file) != -1 && ((*file) += 14))
			material.reflectivity = ft_atoi(*file);
		else if (check_str("refract_coef: ", *file) != -1 && ((*file) += 14))
			material.refract_coef = ft_atof(*file);
		else if (check_str("diffuse: ", *file) != -1 && ((*file) += 9))
			material.diffuse = ft_atoi(*file);
		else
			print_error("Wrong light power info");
		skip_it(file, '\n');
	}
	return (material);
}

void		get_obj_info(char **file, t_scene *scene)
{
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#' && skip_it(file, '\n'))
			continue;
		else if (check_str("\t\t\t", *file) == 1)
			(*file) += 3;
		else if (check_str("\t\t", *file) == 1 || check_str("...", *file) == 1)
			return ;
		get_obj_info_check(file, scene, NULL);
		if (!(scene->objects[scene->last_obj - 1]->material))
			skip_it(file, '\n');
	}
	skip_it(file, '\n');
}

void		get_objs_info(char **file, t_scene *scene)
{
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t\t", *file) != -1)
			get_obj_info(file, scene);
		else if (check_str("\t\t- object:\n", *file) != -1)
			break ;
		else
			print_error("Wrong object data!!!");
	}
}

void		parse_objects(char **file, t_scene *scene)
{
	scene->objects = (t_object **)ft_memalloc(sizeof(t_object *) *
			(STANDART_OBJECT_COUNT + 1));
	scene->last_obj = 0;
	scene->obj_count = STANDART_OBJECT_COUNT;
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t- object:\n", *file) != -1 && ((*file) += 12))
			get_objs_info(file, scene);
		else
			print_error("Wrong objects data!!!");
	}
}
