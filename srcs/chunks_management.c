/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:48:40 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 09:09:36 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*split_chunk(t_chunks *free_chunk, const size_t size)
{
	t_chunks	*new;

	ft_putstr("start split chunk\n");
	free_chunk->allocated = 1;
	if ((free_chunk->size - size) < ALIGNEMENT + sizeof(t_chunks))
		return ((void *)(free_chunk) + sizeof(t_chunks));
	new = (t_chunks *)((void *)(free_chunk) + size);
	new->allocated = 0;
	new->size = free_chunk->size - size - sizeof(t_chunks);
	new->before = free_chunk;
	new->next = free_chunk->next;
	free_chunk->next = new;
	return ((void *)(free_chunk) + sizeof(t_chunks));
}

void			*create_new_chunk_at_end(t_heaps *heap, t_chunks *last,
		const size_t size)
{
	t_chunks	*new;

	heap->size -= size;
	new = (t_chunks *)((void *)(last) + sizeof(t_chunks) + last->size);
	last->next = new;
	new->before = last;
	new->next = NULL;
	new->size = size - sizeof(t_chunks);
	new->allocated = 1;
	return ((void *)(new) + sizeof(t_chunks));
}

void			*get_available_memory(t_heaps *heaps, const size_t size)
{
	t_chunks	*iterator;
	t_chunks	*before;

	ft_putstr("OKOKOK\n");
	while (heaps)
	{
		ft_putstr("startiteration\n");
		iterator = heaps->chunks;
		while (iterator)
		{
			ft_putstr("salut\n");
			ft_putnbr(iterator->size);
			ft_putchar('\n');
			put_memory_hexa((size_t)((void*)(iterator)));
			ft_putchar('\n');
			if (iterator->allocated == 0 && iterator->size >= size)
				return (split_chunk(iterator, size));
			before = iterator;
			iterator = iterator->next;
		}
		ft_putstr("enditeration\n");
		if ((long long)(heaps->size - size) >= 0)
			return (create_new_chunk_at_end(heaps, before, size));
		heaps = heaps->next;
	}
	return (NULL);
}
