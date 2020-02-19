/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:13:38 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 08:45:05 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_heaps			*get_main_heap_of_chunk(t_chunks *to_free)
{
	void		*to_ret;

	to_ret = (void *)(to_free) + to_free->size + sizeof(t_chunks);
	while (to_free)
	{
		to_ret -= sizeof(t_chunks) + to_free->size;
		to_free = to_free->before;
	}
	return ((t_heaps *)(to_ret - sizeof(t_heaps)));
}

void			concatenate_chunk(t_chunks *to_free)
{
	if (to_free->before && to_free->before->allocated == 0)
	{
		to_free->before->size += to_free->size + sizeof(t_chunks);
		to_free->before->next = to_free->next;
		if (to_free->next)
			to_free->next->before = to_free->before;
		to_free = to_free->before;
	}
	if (to_free->next && to_free->next->allocated == 0)
	{
		to_free->size += to_free->next->size + sizeof(t_chunks);
		to_free->next = to_free->next->next;
		if (to_free->next)
			to_free->next->before = to_free;
	}
}

t_heaps			**get_first_heap(t_heaps *main_page)
{
	if (main_page == g_heaps_allocated.tiny_heap)
		return (&g_heaps_allocated.tiny_heap);
	else if (main_page == g_heaps_allocated.small_heap)
		return (&g_heaps_allocated.small_heap);
	else if (main_page == g_heaps_allocated.large_heap)
		return (&g_heaps_allocated.large_heap);
	return (NULL);
}

void			free_all_heap(t_heaps *to_free)
{
	t_heaps		**type_heap;

	if ((type_heap = get_first_heap(to_free)))
	{
		*type_heap = to_free->next;
		if (*type_heap)
			(*type_heap)->before = NULL;
	}
	else
	{
		to_free->before->next = to_free->next;
		if (to_free->next)
			to_free->next->before = to_free->before;
	}
	munmap((void *)(to_free), sizeof(t_heaps) + to_free->size +
		sizeof(t_chunks) + to_free->chunks->size);
}

int	search(t_chunks *to_find, t_heaps *where)
{
	t_chunks	*tmp;

	while (where)
	{
		tmp = where->chunks;
		while(tmp)
		{
			if (tmp == to_find)
				return (1);
			tmp = tmp->next;
		}
		where = where->next;
	}
	return (0);
}

void			free(void *ptr)
{
	t_heaps		*main_heap;
	t_chunks	*to_free;

	if (!ptr)
		return ;
	to_free = (t_chunks *)(ptr - sizeof(t_chunks));
	if (search(to_free, g_heaps_allocated.tiny_heap) == 1 ||
		search(to_free, g_heaps_allocated.small_heap) == 1 ||
		search(to_free, g_heaps_allocated.large_heap) == 1)
	{
		if (to_free->allocated == 1)
		{
			to_free->allocated = 0;
			main_heap = get_main_heap_of_chunk(to_free);
			concatenate_chunk(to_free);
			if (main_heap->chunks->allocated == 0 && !main_heap->chunks->next)
				free_all_heap(main_heap);
		}
	}
}
