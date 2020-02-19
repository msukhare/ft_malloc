/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:58:34 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 01:16:16 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_heaps		*create_new_page(const size_t size, const size_t global_size)
{
	t_heaps	*new;

	if ((new = mmap(NULL, global_size, PROTECTION, FLAGS, -1, 0)) == MAP_FAILED)
		return (NULL);
	new->next = NULL;
	new->before = NULL;
	new->size = global_size - (sizeof(t_heaps) + size);
	new->chunks = (t_chunks *)((void*)(new) + sizeof(t_heaps));
	new->chunks->size = size - sizeof(t_chunks);
	new->chunks->allocated = 1;
	new->chunks->next = NULL;
	new->chunks->before = NULL;
	return (new);
}

void		*allocate_heap(t_heaps **heaps, size_t total_size, size_t chunk_size)
{
	t_heaps	*new_heap;
	t_heaps	*iterator;
	size_t	page_size;

	page_size = getpagesize();
	if (total_size % page_size > 0)
		total_size = ((total_size / page_size) + 1) * page_size;
	if (!(new_heap = create_new_page(chunk_size, total_size)))
		return (NULL);
	iterator = *heaps;
	if (!*heaps)
		*heaps = new_heap;
	else
	{
		while (iterator->next)
			iterator = iterator->next;
		iterator->next = new_heap;
		new_heap->before = iterator;
	}
	return ((void *)(new_heap->chunks) + sizeof(t_chunks));
}
