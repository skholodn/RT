/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:20:12 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 12:14:08 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# define RAY_LEN 2000.f
# define STANDART_LIGHT_COUNT 100
# define STANDART_OBJECT_COUNT 100

# include "window.h"
# include "camera.h"
# include "objects.h"
# include "uf_math.h"
# include "libft.h"
# include "light_model.h"

typedef struct		s_scene
{
	t_window		*window;
	int				win_width;
	int				win_height;
	char			*win_name;
	t_camera		*camera;
	t_object		**objects;
	t_object		**lights;
	t_vec3			ambient;
	char			alising;
	size_t			last_obj;
	size_t			last_light;
	size_t			obj_count;
	size_t			thread_nb;
	size_t			light_count;
}					t_scene;

typedef struct		s_update
{
	float			x;
	float			row;
	float			col;
	int				i;
	t_ray			ray;
}					t_update;

t_scene				*new_scene(int width, int height, char *name,
						t_vec3 ambient);
void				update_scene(t_scene *scene, int y, int finline);
void				get_polygone_data(int file, t_scene *scene,
						char *file_name);
void				read_object(char *filename, t_scene *scene);
char				add_object(t_scene *scene, t_object *obj);
char				add_light(t_scene *scene, t_object *obj);
t_object			*trace(t_ray *ray, t_object **figures);
t_vec3				diffuse(t_ray *ray, t_scene *scene);
t_vec3				reflection(t_ray *ray, t_scene *scene);
t_vec3				refraction(t_ray *ray, t_scene *scene);
t_vec3				get_color(t_ray *ray, t_scene *scene);
t_vec3				get_mid(t_vec3 *colors, int aliasing);
char				set_intersect(t_object *obj, char *type);
void				set_norm(t_object *obj);

#endif
