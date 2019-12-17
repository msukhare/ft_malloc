/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:48:40 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/17 19:46:22 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*create_new_block_at_end(t_pages *page, size_t size)
{
	t_blocks	*iterator;

	iterator = page->blocks;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = (t_blocks*)((void *)(iterator) + sizeof(t_blocks) +
		iterator->size);
	page->size -= size + sizeof(t_blocks);
	iterator->next->size = size;
	iterator->next->allocated = 1;
	iterator->next->next = NULL;
	iterator->next->before = iterator;
	return ((void *)(iterator->next) + sizeof(t_blocks));
}

void			*split_blocks(t_blocks *to_split, size_t size, t_pages *page)
{
	t_blocks	*new;

	to_split->allocated = 1;
	if (size + sizeof(t_blocks) + 16 > to_split->size)
		return ((void *)(to_split) + sizeof(t_blocks));
	new = (t_blocks *)((void *)(to_split) + sizeof(t_blocks) + size);
	new->allocated = 0;
	new->size = to_split->size - (size + sizeof(t_blocks));
	new->next = to_split->next;
	to_split->next = new;
	new->before = to_split;
	if (new->next)
		new->next->before = new;
	to_split->size = size;
	page->size -= sizeof(t_blocks);
	return ((void *)(to_split) + sizeof(t_blocks));
}

void			*get_allocated_page(t_pages *page, size_t size)
{
	t_blocks	*to_ret;

	while (page)
	{
		to_ret = page->blocks;
		while (to_ret)
		{
			if (to_ret->allocated == 0 && to_ret->size >= size)
				return (split_blocks(to_ret, size, page));
			to_ret = to_ret->next;
		}
		if ((long long)(page->size - (size + sizeof(t_blocks))) >= 0)
			return (create_new_block_at_end(page, size));
		page = page->next;
	}
	return (NULL);
}
