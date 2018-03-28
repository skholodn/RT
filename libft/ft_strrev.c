/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:12:43 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/30 10:15:49 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char const *str)
{
	char	*ret_str;
	size_t	len;
	size_t	i;

	ret_str = 0;
	if (str)
	{
		len = ft_strlen(str);
		ret_str = ft_strnew(len);
		i = 0;
		while (i != len)
			ret_str[i] = str[len - 1 - i++];
	}
	return (ret_str);
}
