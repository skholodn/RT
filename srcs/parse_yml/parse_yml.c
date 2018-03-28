/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_yml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:35:46 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 10:08:00 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

void	get_obj_info_check(char **file, t_scene *scene, char *str)
{
	if (check_str("obj_file: ", *file) != -1 && ((*file) += 10))
	{
		str = get_char_str(*file);
		read_object(str, scene);
		free(str);
	}
	else if (check_str("type: ", *file) != -1 && ((*file) += 6))
		get_obj_type(*file, &scene->objects[scene->last_obj - 1]->type);
	else if (check_str("material:\n", *file) != -1 && ((*file) += 10))
		*scene->objects[scene->last_obj - 1]->material =
			get_material_info(file);
	else if (check_str("texture: ", *file) != -1 && ((*file) += 9))
	{
		str = get_char_str(*file);
		scene->objects[scene->last_obj - 1]->texture = read_bump_map(str);
		free(str);
	}
	else
		print_error("Wrong light power info");
}

void	print_error(const char *err)
{
	write(1, "\033[22;32m", ft_strlen("\033[22;32m"));
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	write(1, "\033[0m", ft_strlen("\033[0m"));
	exit(EXIT_FAILURE);
}

size_t	count_words(int fd)
{
	size_t	count;
	ssize_t	red;
	char	one;

	count = 0;
	while ((red = read(fd, &one, 1)))
		count++;
	return (count);
}

int		skip_it(char **file, char c)
{
	while ((*file) && **file != c)
		(*file)++;
	if (!(*file))
		print_error("End of the file (");
	(*file)++;
	return (1);
}
