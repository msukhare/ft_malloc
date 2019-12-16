/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:58:34 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/16 16:44:41 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pages		*create_new_page(const size_t size, const size_t global_size)
{
	t_pages	*new;

	if ((new = mmap(NULL, global_size, PROTECTION, FLAGS, -1, 0)) == MAP_FAILED)
		return (NULL);
	new->next = NULL;
	new->before = NULL;
	new->size = global_size - (sizeof(t_pages) + sizeof(t_blocks) + size);
	new->blocks = (t_blocks *)((void*)(new) + sizeof(t_pages));
	new->blocks->size = size;
	new->blocks->allocated = 1;
	new->blocks->next = NULL;
	new->blocks->before = NULL;
	return (new);
}

size_t		calculate_global_size(size_t type, size_t size)
{
	size_t	to_ret;
	size_t	page_size;

	page_size = getpagesize();
	if (type != SMALL && type != TINY)
		to_ret = size + sizeof(t_pages) + sizeof(t_blocks);
	else
		to_ret = (type * 100) + sizeof(t_pages) + (sizeof(t_blocks) * 100);
	if (to_ret % page_size > 0)
		return (((to_ret / page_size) + 1) * page_size);
	return (to_ret);
}

void		*allocate_page(t_pages **page, size_t type, size_t size)
{
	t_pages	*new_page;
	t_pages	*iterator;

	if (!(new_page = create_new_page(size, calculate_global_size(type, size))))
		return (NULL);
	iterator = *page;
	if (!*page)
		*page = new_page;
	else
	{
		while (iterator->next)
			iterator = iterator->next;
		iterator->next = new_page;
		new_page->before = iterator;
	}
	return ((void *)(new_page->blocks) + sizeof(t_blocks));
}
