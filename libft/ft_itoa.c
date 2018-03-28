/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:15:32 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 19:04:38 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(char **str, int numb)
{
	int		i;

	i = 0;
	if (numb == 0)
	{
		(*str) = ft_strnew(1);
		(*str)[0] = '0';
	}
	else
	{
		if (numb < 0)
			i++;
		while (numb)
		{
			numb = numb / 10;
			i++;
		}
		(*str) = ft_strnew(i);
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*ret_str;
	int		rem;

	size = digit_count(&ret_str, n);
	if (ret_str)
	{
		if (n == 0)
			return (ret_str);
		if (n < 0)
			ret_str[0] = '-';
		while (n != 0)
		{
			rem = n % 10;
			if (rem < 0)
				rem *= -1;
			ret_str[size - 1] = rem + '0';
			n = n / 10;
			size--;
		}
	}
	return (ret_str);
}
