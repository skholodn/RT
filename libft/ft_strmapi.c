/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:17:48 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:36:40 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_str;
	size_t	length;
	size_t	i;

	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	ret_str = ft_strnew(length);
	if (!ret_str)
		return (0);
	i = -1;
	while (++i < length)
		ret_str[i] = f(i, s[i]);
	return (ret_str);
}
