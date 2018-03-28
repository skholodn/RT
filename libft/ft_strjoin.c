/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:08:12 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 19:05:38 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret_str;

	if (!s1 || !s2)
		return (0);
	ret_str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret_str)
	{
		ft_strcat(ret_str, s1);
		ft_strcat(ret_str, s2);
	}
	return (ret_str);
}
