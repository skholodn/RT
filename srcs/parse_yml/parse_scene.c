/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:33:16 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/20 17:35:22 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_yml.h"

size_t	count_smb(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != '"')
		count++;
	if (!str[count])
		return (0);
	else
		return (count);
}

char	*get_char_str(char *str)
{
	char	*begin;
	char	*result;
	size_t	count;

	begin = str;
	if (*str == '"')
		str++;
	if (!(count = count_smb(str)))
		print_error("Wrong path");
	result = (char *)ft_memalloc(count + 1);
	ft_strncpy(result, str, count);
	return (result);
}

void	get_vec_info(char *file, t_vec3 *vec)
{
	if (*file != '{')
		print_error("Wrong vector format");
	else if (file++)
		vec->x = ft_atof(file);
	if (skip_it(&file, ',') && (*file) != ' ')
		print_error("Wrong vector format");
	else if (file++)
		vec->y = ft_atof(file);
	if (skip_it(&file, ',') && (*file) != ' ')
		print_error("Wrong vector format");
	else if (file++)
		vec->z = ft_atof(file);
	if (skip_it(&file, '\n') && (*(file - 2)) != '}')
		print_error("Wrong vector format");
}

void	get_scene_info(char **file, t_scene *scene)
{
	size_t thread_nb;

	if (check_str("window_width: ", *file) != -1 && ((*file) += 14))
		scene->win_width = ft_atoi(*file);
	else if (check_str("window_height: ", *file) != -1 && ((*file) += 15))
		scene->win_height = ft_atoi(*file);
	else if (check_str("window_name: ", *file) != -1 && ((*file) += 13))
		scene->win_name = get_char_str(*file);
	else if (check_str("ambient: ", *file) != -1 && ((*file) += 9))
		get_vec_info(*file, &scene->ambient);
	else if (check_str("alising: ", *file) != -1 && ((*file) += 9))
		scene->alising = (char)ft_atoi(*file);
	else if (check_str("thread_number: ", *file) != -1 && ((*file) += 15))
	{
		thread_nb = (size_t)ft_atoi(*file);
		scene->thread_nb = (thread_nb > 0 && thread_nb < 6) ? thread_nb : 4;
	}
	skip_it(file, '\n');
}

t_scene	*parse_scene(char **file)
{
	t_scene	*scene;

	scene = (t_scene *)ft_memalloc(sizeof(t_scene));
	while (**file && (**file == '\t' || **file == '#'))
	{
		if (**file == '#')
			skip_it(file, '\n');
		else if (check_str("\t\t", *file) != -1 && ((*file) += 2))
			get_scene_info(file, scene);
		else
			print_error("Wrong scene data!!!");
	}
	if (scene->win_width > 0 && scene->win_height > 0 && scene->win_name)
		scene->window = new_window(scene->win_width, scene->win_height,
				scene->win_name);
	else
		print_error("Error window creation");
	if (!scene->thread_nb)
		scene->thread_nb = 1;
	return (scene);
}
