/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:05:32 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 09:40:38 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*merge_chunk(t_chunks *to_increase)
{
	to_increase->size += sizeof(t_chunks) + to_increase->next->size;
	to_increase->next = to_increase->next->next;
	if (to_increase->next)
		to_increase->next->before = to_increase;
	return ((void *)(to_increase) + sizeof(t_chunks));
}

void			*increase_size_of_chunk(t_chunks *to_increase, size_t size,\
		t_heaps *main_heap)
{
	void		*tmp;

	if (to_increase->next == NULL &&
		main_heap->size - (size - to_increase->size) >= 0)
	{
		main_heap->size -= size - to_increase->size;
		to_increase->size = size;
		return ((void *)(to_increase) + sizeof(t_chunks));
	}
	else if (to_increase->next && to_increase->next->allocated == 0 &&
			(size - to_increase->size) <= (to_increase->next->size +
				sizeof(t_chunks)))
		return (merge_chunk(to_increase));
	if (!(tmp = malloc(size)))
		return (NULL);
	memcpy(tmp, (void *)(to_increase) + sizeof(t_chunks), to_increase->size);
	free((void *)(to_increase) + sizeof(t_chunks));
	return (tmp);
}

void			*realloc(void *ptr, size_t size)
{
	t_chunks	*old_chunk;

	if (!ptr)
		return (malloc(size));
	ft_putstr("start realloc: ");
	put_memory_hexa((size_t)((void*)(ptr) - sizeof(t_chunks)));
	ft_putchar('\n');
	if (size == 0)
	{
		free(ptr);
		return (ptr);
	}
	old_chunk = (t_chunks *)(ptr - sizeof(t_chunks));
	if (search(old_chunk, g_heaps_allocated.tiny_heap) == 1 ||
		search(old_chunk, g_heaps_allocated.small_heap) == 1 ||
		search(old_chunk, g_heaps_allocated.large_heap) == 1)
	{
		if (old_chunk->size < size)
		{
			if (size % ALIGNEMENT > 0)
				size = ((size / ALIGNEMENT) + 1) * ALIGNEMENT;
			return (increase_size_of_chunk(old_chunk, size,
				get_main_heap_of_chunk(old_chunk)));
		}
	}
	return (ptr);
}
