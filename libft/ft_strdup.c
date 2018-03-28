/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:32:51 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/25 16:49:37 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret_str;
	size_t	s_length;

	s_length = ft_strlen(s);
	if (!s_length)
		ret_str = ft_memalloc(1);
	else
	{
		ret_str = ft_strnew(s_length);
		if (ret_str)
			ft_memcpy(ret_str, s, s_length);
	}
	return (ret_str);
}
