/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:13:38 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/17 19:22:36 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			free_tiny_and_small_page(t_blocks *to_free, t_pages *page)
{
	to_free->allocated = 0;
	if (to_free->before && to_free->before->allocated == 0)
	{
		page->size += sizeof(t_blocks);
		to_free->before->size += to_free->size + sizeof(t_blocks);
		to_free->before->next = to_free->next;
		if (to_free->next)
			to_free->next->before = to_free->before;
		to_free = to_free->before;
	}
	if (to_free->next && to_free->next->allocated == 0)
	{
		page->size += sizeof(t_blocks);
		to_free->size += to_free->next->size + sizeof(t_blocks);
		to_free->next = to_free->next->next;
		if (to_free->next)
			to_free->next->before = to_free;
	}
}

int				check_if_in_page(void *ptr, t_pages *page)
{
	t_blocks	*iterator;

	while (page)
	{
		iterator = page->blocks;
		while (iterator)
		{
			if ((void *)(iterator) == ptr)
			{
				free_tiny_and_small_page(iterator, page);
				return (1);
			}
			iterator = iterator->next;
		}
		page = page->next;
	}
	return (0);
}

int				free_large_page(void *ptr, t_pages **page)
{
	t_pages		*to_free;

	to_free = *page;
	while (to_free)
	{
		if ((void *)(to_free->blocks) == ptr)
		{
			if (to_free->before)
				to_free->before->next = to_free->next;
			else
			{
				*page = to_free->next;
				if (to_free->next)
					(*page)->before = NULL;
			}
			if (to_free->next)
				to_free->next->before = to_free->before;
			munmap(page, (to_free->size + to_free->blocks->size +
				sizeof(t_blocks) + sizeof(t_pages)));
			return (1);
		}
		to_free = to_free->next;
	}
	return (0);
}

void			ft_free(void *ptr)
{
	if (!ptr)
		return ;
	ptr -= sizeof(t_blocks);
	if (check_if_in_page(ptr, g_pages_allocated.tiny_page) == 1 ||
		check_if_in_page(ptr, g_pages_allocated.small_page) == 1)
		return ;
	else if (free_large_page(ptr, &g_pages_allocated.large_page) == 1)
		return ;
	else
		return ; /*add sig abort */
}
