/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:28:29 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/29 14:51:21 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret_el;
	char	*copy_content;

	ret_el = (t_list *)ft_memalloc(sizeof(t_list));
	if (ret_el)
	{
		if (content)
		{
			copy_content = (char *)ft_memalloc(content_size);
			if (!copy_content)
				return (0);
			ft_memmove(copy_content, content, content_size);
			ret_el->content = copy_content;
			ret_el->content_size = content_size;
		}
	}
	return (ret_el);
}
