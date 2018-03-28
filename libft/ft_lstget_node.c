/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:59:03 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/30 16:21:03 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_node(t_list *start, size_t pos)
{
	size_t i;

	if (start)
	{
		i = 0;
		while (i != pos && start)
		{
			i++;
			start = start->next;
		}
	}
	return (start);
}
