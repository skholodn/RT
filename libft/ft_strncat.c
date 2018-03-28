/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:01 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/26 13:41:42 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	char	*ptr_des;
	size_t	i;

	ptr_des = destination;
	while (*ptr_des)
		ptr_des++;
	i = -1;
	while (++i < num && *source)
		*(ptr_des++) = *(source++);
	*ptr_des = 0;
	return (destination);
}
