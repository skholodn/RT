/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:06:27 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 11:48:04 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parse_yml.h"

void		get_data(t_object *obj, char **arr)
{
	if (arr[0][0] == '#')
	{
		if (arr[1][0] == 'r')
			obj->radius = ft_atof(arr[2]);
		else if (arr[1][0] == 'c')
			obj->center = new_vec3(ft_atof(arr[2]),
					ft_atof(arr[3]), ft_atof(arr[4]));
		else if (arr[1][0] == 'n')
			obj->normal = new_vec3(ft_atof(arr[2]),
					ft_atof(arr[3]), ft_atof(arr[4]));
	}
}

void		get_gshape_in(int file, char **line, t_object *object, char **split)
{
	while (get_next_line(file, line))
	{
		set_no_ws(line);
		split = ft_strsplit(*line, ' ');
		get_data(object, split);
		free_after_split(&split);
		free(*line);
	}
}

t_object	*get_gshape_data(int file, char **line)
{
	t_object	*object;
	char		**split;

	object = new_object();
	if (ft_strchr(*line, '.'))
	{
		split = ft_strsplit(*line, '.');
		object->name = ft_strdup(split[0] + 2);
		if (!set_intersect(object, split[1]))
			delete_object(&object);
		else
		{
			free_after_split(&split);
			free(*line);
			get_gshape_in(file, line, object, split);
		}
	}
	else
		delete_object(&object);
	return (object);
}

void		read_object(char *filename, t_scene *scene)
{
	int			file;
	char		*line;

	file = open(filename, O_RDONLY);
	if (file == -1 || file == 0)
		print_error("Reading error: no such obj file");
	while (get_next_line(file, &line) == 1)
	{
		set_no_ws(&line);
		if (*line == 'o')
		{
			if (!add_object(scene, get_gshape_data(file, &line)))
				get_polygone_data(file, scene, filename);
			free(line);
			close(file);
			return ;
		}
		free(line);
	}
	close(file);
}
