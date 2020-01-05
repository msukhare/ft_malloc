/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:05:32 by msukhare          #+#    #+#             */
/*   Updated: 2020/01/05 13:33:18 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			extend_memory_block(t_blocks *to_extend, size_t size)
{
	t_blocks	*new_block;
	t_blocks	*new_next;
	size_t		new_size;

	new_size = to_extend->next->size - (size - to_extend->size);
	new_next = to_extend->next->next;
	new_block = (void *)(to_extend) + sizeof(t_blocks) + size;
	new_block->allocated = 0;
	new_block->size = new_size;
	new_block->next = new_next;
	if (new_next)
		new_next->before = new_block;
	new_block->before = to_extend;
	to_extend->size = size;
	to_extend->next = new_block;
}

void			*reallocate_block(t_blocks *old_block, t_pages *main_page,
	size_t size)
{
	void		*to_ret;

	if (!old_block->next &&
		(long long)(main_page->size - (size - old_block->size)) >= 0)
	{
		main_page->size -= (size - old_block->size);
		old_block->size = size;
	}
	else if (old_block->next && old_block->next->allocated == 0 &&
		(size - old_block->size) + 16 <= old_block->next->size)
		extend_memory_block(old_block, size);
	else
	{
		if (!(to_ret = malloc(size)))
		{
			ft_putstr("return NULL\n");
			return (NULL);
		}
		ft_memcpy(to_ret, (void *)(old_block) + sizeof(t_blocks),
			old_block->size);
		free((void *)(old_block) + sizeof(t_blocks));
		//ft_putstr("return new_allocation in realloc: ");
		//put_memory_hexa((size_t)(to_ret));
		//ft_putchar('\n');
		//read_ptr(to_ret, size, "new malloced ptr realloc\n");
		//ft_putstr("return new ptr realloc\n");
		return (to_ret);
	}
	//ft_putstr("return unchange allocation in realloc: ");
	//put_memory_hexa((size_t)((void*)(old_block) + sizeof(t_blocks)));
	//ft_putchar('\n');
	//read_ptr((void *)(old_block) + sizeof(t_blocks), size, "old ptr in realloc\n");
	//ft_putstr("return old ptr realloc\n");
	return ((void *)(old_block) + sizeof(t_blocks));
}

void			*realloc(void *ptr, size_t size)
{
	t_blocks	*old_block;

	//ft_putstr("call realloc\n");
	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		//ft_putstr("return free block: ");
		//put_memory_hexa((size_t)(ptr));
		//ft_putchar('\n');
		//ft_putstr("free ptr\n");
		return (ptr);
	}
	old_block = (t_blocks *)(ptr - sizeof(t_blocks));
	if (old_block->size < size)
		return (reallocate_block(old_block, get_main_page_of_block(old_block),
			size));
	//ft_putstr("return realloc do nothing: ");
	//put_memory_hexa((size_t)(ptr));
	//ft_putchar('\n');
	//read_ptr(ptr, size, "nothing done in realloc\n");
	//ft_putstr("nothing done\n");
	return (ptr);
}
