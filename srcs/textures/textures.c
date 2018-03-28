/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:29:13 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 18:28:46 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <parse_yml.h>

t_texture	read_bump_map(char *addr)
{
	t_texture	texture;

	if (!ft_strcmp(addr, "none"))
	{
		texture.is_texture = 0;
		return (texture);
	}
	texture.mlx = mlx_init();
	texture.img_bump = mlx_xpm_file_to_image(texture.mlx,
		addr, &texture.w, &texture.h);
	if (!texture.img_bump)
		print_error("Bad texture!");
	texture.arr_bump = (int *)mlx_get_data_addr(texture.img_bump, &texture.bits,
		&texture.size_line, &texture.endians);
	texture.is_texture = 1;
	return (texture);
}

t_vec3		get_sphere_texture(t_object *f, t_vec3 *p)
{
	double	s;
	double	t;
	int		xy[2];
	int		rot;
	t_vec3	phit_color[2];

	phit_color[0] = sub_vec3(*p, f->center);
	normalize_vec3(&phit_color[0]);
	s = 0.5 + (atan2(phit_color[0].z, phit_color[0].x) / (2 * M_PI));
	t = 0.5 - (asin(phit_color[0].y) / M_PI);
	xy[0] = (s * f->texture.w);
	xy[1] = (t * f->texture.h);
	rot = 0;
	phit_color[1] = new_vec3(((f->texture.arr_bump[xy[0] +
		rot + (f->texture.w * xy[1])] >> 16) & 255) / 255.0f,
		((f->texture.arr_bump[xy[0] +
		rot + (f->texture.w * xy[1])] >> 8) & 255) / 255.0f,
		(f->texture.arr_bump[xy[0] +
		rot + (f->texture.w * xy[1])] & 255) / 255.0f);
	return (phit_color[1]);
}
