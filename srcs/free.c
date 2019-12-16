/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:13:38 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/16 17:14:54 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_blocks		*check_if_in_page(void *ptr, t_pages *page)
{
	t_blocks	*iterator;

	while (page)
	{
		iterator = page->blocks;
		while (iterator)
		{
			if ((void *)(iterator) + sizeof(t_blocks) == ptr)
				return (iterator);
			iterator = iterator->next;
		}
		page = page->next;
	}
	return (NULL);
}

void			ft_free(void *ptr)
{
	//t_blocks	*to_free;

	if (!ptr)
		return ;
	ft_putnbr(((t_blocks *)(ptr - sizeof(t_blocks)))->size);
	//if ((to_free = check_if_in_page(ptr, g_pages_allocated.tiny_page)) ||
	//	(to_free = check_if_in_page(ptr, g_pages_allocated.small_page)))
	//	return ;
	//else
	//	free_large_page(ptr);
}
