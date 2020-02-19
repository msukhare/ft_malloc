/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:30:57 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 09:04:05 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			put_memory_hexa(size_t adress)
{
	char		*base;
	char		hexa[32];
	int			i;


	base = "0123456789abcdef";
	i = 0;
	while (adress > 0)
	{
		hexa[i] = base[adress % 16];
		adress /= 16;
		i += 1;
	}
	hexa[i] = '\0';
	ft_rev(hexa);
	ft_putstr(hexa);
}

void			read_pages(t_heaps *heap, char *type)
{
	t_chunks	*iterator;

	while (heap)
	{
		ft_putstr(type);
		ft_putstr(" : ");
		put_memory_hexa((size_t)((void *)(heap)));
		ft_putchar('\n');
		iterator = heap->chunks;
		while (iterator)
		{
			put_memory_hexa((size_t)((void *)(iterator) + sizeof(t_chunks)));
			ft_putstr(" - ");
			put_memory_hexa((size_t)((void *)(iterator) + sizeof(t_chunks) +
				iterator->size));
			ft_putstr(" : ");
			ft_putnbr(iterator->size);
			ft_putstr(" bytes\n");
			iterator = iterator->next;
		}
		heap = heap->next;
	}
}

void			show_alloc_mem()
{
	ft_putstr(COLOR_TINY);
	read_pages(g_heaps_allocated.tiny_heap, "TINY");
	ft_putstr(END_COLOR);
	ft_putstr(COLOR_SMALL);
	read_pages(g_heaps_allocated.small_heap, "SMALL");
	ft_putstr(END_COLOR);
	ft_putstr(COLOR_LARGE);
	read_pages(g_heaps_allocated.large_heap, "LARGE");
	ft_putstr(END_COLOR);
	ft_putstr("\n");
}
