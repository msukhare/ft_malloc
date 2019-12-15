/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:56 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/15 15:56:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pages_allocated	g_pages_allocated = {NULL, NULL, NULL};

t_pages				*create_new_page(size_t size, size_t global_size)
{
	t_pages			*new;

	if ((new = mmap(NULL, global_size, PROTECTION, FLAGS, -1, 0)) == MAP_FAILED)
		return (NULL);
	new->next = NULL;
	new->before = NULL;
	new->size = size;
	new->blocks = (t_blocks *)((void*)(new) + sizeof(t_pages));
	new->blocks->size = size;
	new->blocks->allocated = 1;
	new->blocks->next = NULL;
	new->blocks->before = NULL;
	return (new);
}

size_t				calculate_global_size(size_t type)
{
	size_t			to_ret;
	size_t			page_size;

	page_size = getpagesize();
	to_ret = (type * 100) + sizeof(t_pages) + (sizeof(t_blocks) * 100);
	if (to_ret % page_size > 0)
		return (((to_ret / page_size) + 1) * page_size);
	return (to_ret);
}

void				*allocate_page(t_pages **page, size_t type, size_t size)
{
	t_pages			*new_page;
	t_pages			*iterator;
	
	if (!(new_page = create_new_page(size, calculate_global_size(type))))
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

void				*create_new_block_at_end(t_pages *page, size_t size)
{
	t_blocks		*iterator;

	iterator = page->blocks;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = (t_blocks*)((void *)(iterator) + sizeof(t_blocks) + iterator->size);
	page->size += size;
	iterator->next->size = size;
	iterator->next->allocated = 1;
	iterator->next->next = NULL;
	iterator->next->before = iterator;
	return ((void *)(iterator->next) + sizeof(t_blocks));
}

void				*get_allocated_page(t_pages *page, size_t size, size_t type)
{
	t_blocks		*to_ret;

	while (page)
	{
		to_ret = page->blocks;
		while (to_ret)
		{
			if (to_ret->allocated == 0 && to_ret->size >= size)
			{
				//split_blocks
				return ((void *)to_ret + sizeof(t_blocks));
			}
			to_ret = to_ret->next;
		}
		if (page->size + size <= type * 100 &&
			(to_ret = create_new_block_at_end(page, size)))
			return (to_ret);
		page = page->next;
	}
	return (NULL);
}

void				*ft_malloc(size_t size)
{
	void			*to_ret;
	t_pages			*page;
	t_blocks		*blocks;

	page = g_pages_allocated.tiny_page;
	while (page)
	{
		blocks = page->blocks;
		ft_putstr("\x1b[0;31m page_size = ");
		ft_putnbr(page->size);
		ft_putstr("\n");
		while (blocks)
		{
			ft_putstr("\x1b[0m \x1b[0;32m blocks_size =");
			ft_putnbr(blocks->size);
			ft_putstr(", allocated =");
			ft_putnbr(blocks->allocated);
			ft_putstr("\x1b[0m\n");
			blocks = blocks->next;
		}
		ft_putstr("\n\n");
		page = page->next;
	}
	if (size <= 0 || size > TINY)
		return (NULL);
	if (!(to_ret = get_allocated_page(g_pages_allocated.tiny_page, size, TINY)))
		return (allocate_page(&g_pages_allocated.tiny_page, TINY, size));
	return (to_ret);
}
