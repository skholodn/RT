/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:49:22 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:16:58 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret_str;
	size_t	i;
	size_t	length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	ret_str = ft_strnew(length);
	i = 0;
	if (ret_str)
		while (i < length)
			ret_str[i++] = f(*(s++));
	return (ret_str);
}
