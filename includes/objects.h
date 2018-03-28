/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:17:58 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 12:09:13 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_OBJECTS_H
# define RTV1_OBJECTS_H

# include "uf_math.h"
# include "libft.h"
# include "fcntl.h"
# include <mlx.h>

struct s_ray;

typedef struct	s_material
{
	char		*name;
	t_vec3		color;
	float		diffuse;
	float		reflectivity;
	float		transparency;
	float		refract_coef;
}				t_material;

typedef struct	s_reader
{
	t_vec3		*vn;
	t_vec3		*v;
	int			vn_count;
	int			v_count;
}				t_reader;

typedef	struct	s_texture
{
	void		*img_bump;
	int			endians;
	int			bits;
	int			size_line;
	int			*arr_bump;
	int			w;
	int			h;
	void		*mlx;
	int			is_texture;
}				t_texture;

/*
** sphere - 1; plane - 2; cylinders - 3; cones - 4; triangle - 5; disc - 6
*/

typedef struct	s_object
{
	char		*name;
	int			type;
	t_vec3		center;
	t_vec3		normal;
	t_material	*material;
	float		radius;
	t_vec3		*vertexes;
	char		(*intersect)(struct s_ray *, struct s_object *, float *t);
	t_vec3		(*norm)(struct s_object *, t_vec3 *);
	t_texture	texture;
}				t_object;

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	t_object	*obj;
	float		power;
	float		t;
	t_vec3		hit;
	t_vec3		hit_normal;
}				t_ray;

typedef struct	s_triangle_intersect
{
	t_vec3		e1;
	t_vec3		e2;
	t_vec3		pvec;
	t_vec3		tvec;
	t_vec3		qvec;
	float		det;
	float		u;
	float		v;
}				t_triangle_intersect;

t_material		*new_material(void);
t_object		*new_triangle(t_vec3 v1, t_vec3 v2, t_vec3 v3,
				t_material *material);
t_object		*new_disk(t_vec3 center, t_vec3 normal, float radius,
				t_material *material);
t_object		*new_sphere(t_vec3 center, float radius, t_material *material);
t_object		*new_object(void);
void			delete_object(t_object **obj);
t_object		*new_cylinder(t_vec3 center, t_vec3 normal, float radius,
				t_material *material);
t_object		*new_cone(t_vec3 center, t_vec3 normal, float angle,
				t_material *material);
t_object		*new_plane(t_vec3 center, t_vec3 normal, t_material *material);
t_object		*new_light(t_vec3 pos, t_vec3 power);
t_vec3			get_hit(t_ray *ray);

char			init_sphere_behavior(t_object *obj);
char			init_cone_behavior(t_object *obj);
char			init_cylinder_behavior(t_object *obj);
char			init_triangle_behavior(t_object *obj);
char			init_plane_behavior(t_object *obj);
char			init_disk_behavior(t_object *obj);

char			sphere_intersect(t_ray *ray, t_object *sphere, float *t);
t_vec3			sphere_norm(t_object *sphere, t_vec3 *phit);

char			plane_intersect(t_ray *ray, t_object *plane, float *t);
t_vec3			plane_norm(t_object *sphere, t_vec3 *phit);

char			triangle_intersect(t_ray *ray, t_object *triangle, float *t);
t_vec3			triangle_norm(t_object *sphere, t_vec3 *phit);

char			cylinder_intersect(t_ray *r, t_object *f, float *t);
t_vec3			cylinder_norm(t_object *sphere, t_vec3 *phit);

char			cone_intersect(t_ray *r, t_object *f, float *t);
t_vec3			cone_norm(t_object *sphere, t_vec3 *phit);

char			plane_intersect(t_ray *ray, t_object *plane, float *t);
t_texture		read_bump_map(char *addr);
t_vec3			get_sphere_texture(t_object *f, t_vec3 *p);
t_vec3			get_plane_texture(t_object *f, t_vec3 *p);

#endif
