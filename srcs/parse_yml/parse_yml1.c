/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_yml1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:38:15 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/20 17:40:57 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

void	check_begin_end(char **file, size_t nb)
{
	int		three;

	three = 3;
	while (three--)
		if (*(*file)++ != '-')
			print_error("Wrong file format: file must begin with tags '---'");
	**file == '\n' ? (*file)++ : print_error("Wrong file format");
	three = 3;
	nb -= 4;
	while (three-- && --nb)
		if ((*file)[nb] != '.')
			print_error("Wrong file format: file must end with tags '...'");
}

int		check_str(const char *to_find, const char *where)
{
	while (*to_find)
	{
		if (*to_find == *where && *where)
			where++;
		else
			return (-1);
		to_find++;
	}
	return (1);
}

void	parse_yml(char *file, size_t nb)
{
	char	*begin;
	t_scene *scene;

	begin = file;
	check_begin_end(&file, nb);
	scene = NULL;
	while (check_str("...", file) == -1)
	{
		if (check_str("scene:\n", file) != -1 && (file += 7))
			scene = parse_scene(&file);
		if (scene && check_str("camera:\n", file) != -1 && (file += 8))
			scene->camera = parse_camera(&file);
		if (!scene || !(scene->camera))
			print_error("Camera and scene problems");
		if (check_str("lights:\n", file) != -1 && (file += 8))
			parse_lights(&file, scene);
		if (check_str("objects:\n", file) != -1 && (file += 9))
			parse_objects(&file, scene);
	}
	free(begin);
	new_control(scene, scene->thread_nb);
}
