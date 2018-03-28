/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:44:40 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 10:24:04 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	char *start_dest;

	start_dest = destination;
	while (*source)
		*(destination++) = *(source++);
	*(destination) = *(source);
	return (start_dest);
}
