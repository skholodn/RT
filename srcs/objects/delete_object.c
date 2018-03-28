/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:34:20 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:34:25 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void			delete_object(t_object **obj)
{
	free((*obj)->name);
	free((*obj)->vertexes);
	free((*obj)->material);
	free(*obj);
	*obj = 0;
}
