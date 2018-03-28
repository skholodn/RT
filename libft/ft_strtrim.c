/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:13:54 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/30 11:47:02 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*end_s;
	char	*ret_str;

	if (s)
	{
		while (ft_isspace(*s) && *s)
			s++;
		end_s = ft_strrchr(s, 0);
		while (ft_isspace(*(end_s - 1)) && end_s > s)
			end_s--;
		ret_str = (char *)ft_memalloc(end_s - s + 1);
		if (ret_str && (end_s - s))
			ft_memmove(ret_str, s, end_s - s);
		return (ret_str);
	}
	return (0);
}
