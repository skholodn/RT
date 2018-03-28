/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:12:36 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/26 16:10:26 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char *cur_pos;

	cur_pos = 0;
	while (*s)
	{
		if (*s == (char)ch)
			cur_pos = (char *)((size_t)s);
		s++;
	}
	if (!ch)
		return ((char*)((size_t)s));
	return (cur_pos);
}
