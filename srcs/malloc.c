/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:56 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 09:57:53 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_heaps_allocated	g_heaps_allocated = {NULL, NULL, NULL};

void		*init_malloc(t_heaps **heap, size_t type, size_t size)
{
	void	*to_ret;

	ft_putstr("init_malloc\n");
	size += sizeof(t_chunks);
	if (size % ALIGNEMENT > 0)
		size = ((size / ALIGNEMENT) + 1) * ALIGNEMENT;
	if ((to_ret = get_available_memory(*heap, size)))
		return (to_ret);
	ft_putstr("after get_available_memory\n");
	return (allocate_heap(heap, type * 100 + sizeof(t_heaps) +\
			sizeof(t_chunks) * 100, size));
}

void		*malloc(size_t size)
{
	void	*to_ret;

	ft_putstr("start malloc\n");
	if (size == 0)
		return (NULL);
	if (size <= TINY)
		to_ret = init_malloc(&g_heaps_allocated.tiny_heap, TINY, size);
	else if (size <= SMALL)
		to_ret = init_malloc(&g_heaps_allocated.small_heap, SMALL, size);
	else
		to_ret = allocate_heap(&g_heaps_allocated.large_heap, size +
			sizeof(t_heaps) + sizeof(t_chunks), size);
	ft_putstr("end malloc\n");
	put_memory_hexa((size_t)((void*)(to_ret) - sizeof(t_chunks)));
	ft_putchar('\n');
	return (to_ret);
}
