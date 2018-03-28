/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_yml.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:09:33 by skholodn          #+#    #+#             */
/*   Updated: 2017/07/21 12:11:17 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_YML_H
# define RT_PARSE_YML_H

# include "scene.h"
# include "control.h"

void		parse_yml(char *file, size_t nb);
void		print_error(const char *err);
t_scene		*parse_scene(char **file);
t_camera	*parse_camera(char **file);
int			skip_it(char **file, char c);
int			check_str(const char *to_find, const char *where);
void		get_vec_info(char *file, t_vec3 *vec);
void		parse_lights(char **file, t_scene *scene);
void		parse_objects(char **file, t_scene *scene);
char		*get_char_str(char *str);
size_t		count_words(int fd);
void		get_obj_info_check(char **file, t_scene *scene, char *str);
t_material	get_material_info(char **file);
void		get_obj_type(char *file, int *type);

#endif
