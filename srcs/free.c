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

t_pages			*get_main_page_of_block(t_blocks *to_free)
{
	void		*to_ret;

	to_ret = (void *)(to_free) + to_free->size + sizeof(t_blocks);
	while (to_free)
	{
		to_ret -= sizeof(t_blocks) + to_free->size;
		to_free = to_free->before;
	}
	return ((t_pages *)(to_ret - sizeof(t_pages)));
}

void			concatenate_blocks(t_blocks *to_free)
{
	if (to_free->before && to_free->before->allocated == 0)
	{
		to_free->before->size += to_free->size + sizeof(t_blocks);
		to_free->before->next = to_free->next;
		if (to_free->next)
			to_free->next->before = to_free->before;
		to_free = to_free->before;
	}
	if (to_free->next && to_free->next->allocated == 0)
	{
		to_free->size += to_free->next->size + sizeof(t_blocks);
		to_free->next = to_free->next->next;
		if (to_free->next)
			to_free->next->before = to_free;
	}
}

t_pages			**get_first_page(t_pages *main_page)
{
	if (main_page == g_pages_allocated.tiny_page)
		return (&g_pages_allocated.tiny_page);
	else if (main_page == g_pages_allocated.small_page)
		return (&g_pages_allocated.small_page);
	else if (main_page == g_pages_allocated.large_page)
		return (&g_pages_allocated.large_page);
	return (NULL);
}

void			free_all_page(t_pages *to_free)
{
	t_pages		**type_page;

	if ((type_page = get_first_page(to_free)))
	{
		*type_page = to_free->next;
		if (*type_page)
			(*type_page)->before = NULL;
	}
	else
	{
		to_free->before->next = to_free->next;
		if (to_free->next)
			to_free->next->before = to_free->before;
	}
	munmap((void *)(to_free), sizeof(t_pages) + to_free->size +
		sizeof(t_blocks) + to_free->blocks->size);
}

int	search(t_blocks *to_find, t_pages *where)
{
	t_blocks	*tmp;

	while (where)
	{
		tmp = where->blocks;
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
	t_pages		*main_page;
	t_blocks	*to_free;

	//ft_putstr("free: ");
	//put_memory_hexa((size_t)(ptr));
	//ft_putchar('\n');
	ft_putstr("call free\n");
	if (!ptr)
		return ;
	to_free = (t_blocks *)(ptr - sizeof(t_blocks));
	if (search(to_free, g_pages_allocated.tiny_page) == 1 ||
		search(to_free, g_pages_allocated.small_page) == 1 ||
		search(to_free, g_pages_allocated.large_page) == 1)
	{
		ft_putstr("free ptr\n");
		if (to_free->allocated == 1)
		{
			to_free->allocated = 0;
			main_page = get_main_page_of_block(to_free);
			concatenate_blocks(to_free);
			if (main_page->blocks->allocated == 0 && !main_page->blocks->next)
				free_all_page(main_page);
		}
		ft_putstr("success free\n");
	}
	else
	{
		ft_putstr("fail to find adress: ");
		put_memory_hexa((size_t)(ptr));
		ft_putchar('\n');
	}
}
