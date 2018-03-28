#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:49:42 by dpylypen          #+#    #+#              #
#    Updated: 2017/07/21 11:41:01 by dpylypen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RT

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I/Library/Frameworks/SDL2.framework/Headers/ -I/usr/local/include

INCLUDES =  includes/

SRCS =	srcs/main.c\
        srcs/window/new_window.c\
        srcs/scene/update_scene.c\
        srcs/window/set_pixel.c\
        srcs/uf_math/new_vec3.c\
        srcs/uf_math/normalize.c\
        srcs/uf_math/length_vec3.c\
        srcs/uf_math/dot_vec3.c\
        srcs/uf_math/mul_vec3.c\
        srcs/uf_math/add_vec3.c\
        srcs/camera/new_camera.c\
        srcs/uf_math/sub_vec3.c\
        srcs/uf_math/mul_vec3_numb.c\
        srcs/objects/sphere.c\
        srcs/uf_math/reflect_vec3.c\
        srcs/objects/plane.c\
        srcs/objects/cylinder.c\
        srcs/objects/cone.c\
        srcs/objects/get_hit.c\
        srcs/uf_math/get_direction.c\
        srcs/light_model/phong_light.c\
        srcs/light_model/lambert_light.c\
        srcs/light_model/combo_light.c\
        srcs/uf_math/mul_in_vec.c\
        srcs/uf_math/add_in_vec.c\
        srcs/control/new_control.c\
        srcs/control/key_press.c\
        srcs/control/key_release.c\
        srcs/control/mouse_press.c\
        srcs/control/mouse_release.c\
        srcs/control/move.c\
        srcs/control/next_obj.c\
        srcs/control/mouse_move.c\
        srcs/window/window_update.c\
        srcs/main_loop.c\
        srcs/control/start_render.c\
        srcs/thread/get_threads.c\
        srcs/uf_math/top_round.c\
        srcs/objects/triangle.c\
        srcs/uf_math/refract_vec3.c\
        srcs/objects/disk.c\
        srcs/scene/read_object.c\
        srcs/objects/delete_object.c\
        srcs/objects/add_object.c\
        srcs/objects/new_object.c\
        srcs/scene/read_poly.c\
        srcs/textures/textures.c\
        srcs/parse_yml/parse_yml.c\
        srcs/parse_yml/parse_yml1.c\
        srcs/parse_yml/parse_camera.c\
        srcs/parse_yml/parse_lights.c\
        srcs/parse_yml/parse_objects.c\
        srcs/parse_yml/parse_scene.c\
        srcs/objects/new_material.c\
        srcs/scene/update_scene_2.c\
        srcs/scene/update_scene_3.c

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft -L/usr/local/lib/ -lmlx -lm -framework OpenGL -F /Library/Frameworks -framework SDL2 -framework AppKit

%.o: %.c
	$(CC) -I $(INCLUDES) $(CFLAGS) -c  -o $@ $<

$(LIBFTDIR)libft.a: libft/Makefile
		make -C $(LIBFTDIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re:  fclean all
	make re -C $(LIBFTDIR)

norm:
	norminette $(INCLUDES)
	norminette $(SRCS)

rmsh:
	find . -name ".DS*" -o -name "._.*" -o -name "#*" -o -name "*~" -o -name "*.out" > rmsh
	xargs rm < rmsh
	rm rmsh