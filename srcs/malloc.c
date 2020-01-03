/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:56 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/18 22:08:38 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pages_allocated	g_pages_allocated = {NULL, NULL, NULL};

void				read_ptr(void *ptr, size_t size, char *mess)
{
	size_t			i = 0;
	char			*tmp;

	ft_putstr(mess);
	tmp = ptr;
	while (i < size)
	{
		ft_putstr("ok: ");
		ft_putchar(tmp[i]);
		ft_putchar(',');
		i += 1;
	}
	ft_putchar('\n');
	ft_putstr("all ok\n");
}

void analyse_page(t_pages *page)
{
	t_blocks	*tmp;

	while (page)
	{
		ft_putstr("size_page : ");
		ft_putnbr(page->size);
		ft_putchar('\n');
		tmp = page->blocks;
		while (tmp)
		{
			ft_putstr("block size : ");
			ft_putnbr(tmp->size);
			ft_putchar('\n');
			tmp = tmp->next;
		}
		page = page->next;
	}
}

void				*malloc(size_t size)
{
	void			*to_ret;

	ft_putstr("come to malloc\n");
	if (size == 0)
	{
		ft_putstr("return NULL size equal ");
		ft_putnbr(size);
		ft_putchar('\n');
		return (NULL);
	}
	if (size <= TINY)
	{
		if (!(to_ret = get_allocated_page(g_pages_allocated.tiny_page, size)))
			return (allocate_page(&g_pages_allocated.tiny_page, TINY, size));
	}
	else if (size <= SMALL)
	{
		if (!(to_ret = get_allocated_page(g_pages_allocated.small_page, size)))
			return (allocate_page(&g_pages_allocated.small_page, SMALL, size));
	}
	else
		return (allocate_page(&g_pages_allocated.large_page, 0, size));
	//read_ptr(to_ret, size, "not mmaped ptr malloc\n");
	//analyse_page(g_pages_allocated.tiny_page);
	//analyse_page(g_pages_allocated.small_page);
	//analyse_page(g_pages_allocated.large_page);
	//show_alloc_mem();
	return (to_ret);
}
