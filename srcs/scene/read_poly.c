/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_poly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:12:21 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 11:46:34 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	add_from_face(t_scene *scene, t_reader *reader, char *str)
{
	char		**split;
	t_object	*obj;

	obj = new_object();
	obj->intersect = triangle_intersect;
	obj->vertexes = (t_vec3 *)ft_memalloc(sizeof(t_vec3) * 3);
	split = ft_strsplit(str, ' ');
	obj->norm = plane_norm;
	obj->vertexes[0] = reader->v[ft_atoi(split[1]) - 1];
	obj->vertexes[1] = reader->v[ft_atoi(split[2]) - 1];
	obj->vertexes[2] = reader->v[ft_atoi(split[3]) - 1];
	set_norm(obj);
	free_after_split(&split);
	add_object(scene, obj);
}

void	get_poly_info_in(int file, char *line)
{
	while (get_next_line(file, &line) == 1)
	{
		set_no_ws(&line);
		if (*line == 'o')
		{
			free(line);
			return ;
		}
		free(line);
	}
}

void	get_poly_info(t_reader *info, int file, char *file_name)
{
	char	*line;

	info->v_count = 0;
	info->vn_count = 0;
	line = 0;
	while (get_next_line(file, &line))
	{
		set_no_ws(&line);
		if (ft_strstr(line, "v ") == line)
			info->v_count++;
		else if (ft_strstr(line, "vn ") == line)
			info->vn_count++;
		free(line);
	}
	info->v = (t_vec3 *)ft_memalloc(sizeof(t_vec3) * info->v_count);
	info->vn = (t_vec3 *)ft_memalloc(sizeof(t_vec3) * info->vn_count);
	close(file);
	file = open(file_name, O_RDONLY);
	get_poly_info_in(file, line);
	free(line);
}

void	set_vec3_line(char *line, t_vec3 *vec)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	vec->x = ft_atof(split[1]);
	vec->y = ft_atof(split[2]);
	vec->z = ft_atof(split[3]);
	free_after_split(&split);
}

void	get_polygone_data(int file, t_scene *scene, char *file_name)
{
	t_reader	info;
	char		*line;
	int			i;
	int			j;

	get_poly_info(&info, file, file_name);
	i = 0;
	j = 0;
	while (get_next_line(file, &line))
	{
		set_no_ws(&line);
		if (ft_strstr(line, "v ") == line)
			set_vec3_line(line, &(info.v[i++]));
		else if (ft_strstr(line, "vn ") == line)
			set_vec3_line(line, &(info.vn[j++]));
		else if (ft_strstr(line, "f ") == line)
			add_from_face(scene, &info, line);
		free(line);
	}
	free(info.v);
	free(info.vn);
	free(line);
}
