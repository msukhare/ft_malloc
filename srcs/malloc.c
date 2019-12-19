/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:56 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/18 22:08:38 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pages_allocated	g_pages_allocated = {NULL, NULL, NULL};

void				*ft_malloc(size_t size)
{
	void			*to_ret;

	if (size == 0)
		return (NULL);
	if (size <= TINY)
	{
		if (!(to_ret = get_allocated_page(g_pages_allocated.tiny_page, size)))
			return (allocate_page(&g_pages_allocated.tiny_page, TINY, size));
	}
	else if (size <= SMALL)
	{
		if (!(to_ret = get_allocated_page(g_pages_allocated.small_page, size)))
			return (allocate_page(&g_pages_allocated.small_page, SMALL, size));
	}
	else
		return (allocate_page(&g_pages_allocated.large_page, 0, size));
	return (to_ret);
}
