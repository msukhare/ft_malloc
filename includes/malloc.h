/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:47:03 by msukhare          #+#    #+#             */
/*   Updated: 2020/02/19 09:04:10 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>
# include "../libft/include/libft.h"

/* define all heap size available */

# define TINY				1024
# define SMALL				127e3

# define ALIGNEMENT			16

# define PROTECTION 		(PROT_READ | PROT_WRITE)
# define FLAGS 				(MAP_SHARED | MAP_ANONYMOUS)

# define COLOR_TINY 		"\x1b[31m"
# define COLOR_SMALL		"\x1b[32m"
# define COLOR_LARGE 		"\x1b[33m"
# define END_COLOR 			"\x1b[0m"

/* Create all structurs which are useful*/

typedef struct				s_chunks
{
	short int				allocated;
	size_t					size;
	struct s_chunks			*next;
	struct s_chunks			*before;
}							t_chunks;

typedef struct				s_heaps
{
	size_t					size;
	t_chunks				*chunks;
	struct s_heaps			*next;
	struct s_heaps			*before;
}							t_heaps;

typedef struct				s_heaps_allocated
{
	t_heaps					*tiny_heap;
	t_heaps					*small_heap;
	t_heaps					*large_heap;
}							t_heaps_allocated;

extern t_heaps_allocated	g_heaps_allocated;

/* internal function to librairy */
void						*allocate_heap(t_heaps **heaps, size_t type,
		size_t size);
void						*get_available_memory(t_heaps *heaps,\
		const size_t size);
t_heaps			*			get_main_heap_of_chunk(t_chunks *to_free);


int	search(t_chunks *to_find, t_heaps *where);
void			put_memory_hexa(size_t adress);


/*functions of librairy */
void						*malloc(size_t size);
void						free(void *ptr);
void						show_alloc_mem();
#endif
