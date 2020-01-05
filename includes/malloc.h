/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:47:03 by msukhare          #+#    #+#             */
/*   Updated: 2020/01/05 14:04:28 by msukhare         ###   ########.fr       */
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

/* define all page size available */

# define TINY 512
# define SMALL 2048

# define PROTECTION 		(PROT_READ | PROT_WRITE)
# define FLAGS 				(MAP_SHARED | MAP_ANONYMOUS)

# define COLOR_TINY 		"\x1b[31m"
# define COLOR_SMALL		"\x1b[32m"
# define COLOR_LARGE 		"\x1b[33m"
# define END_COLOR 			"\x1b[0m"

/* Create all structurs which are useful*/

typedef struct				s_blocks
{
	size_t					size;
	short int				allocated;
	struct s_blocks			*next;
	struct s_blocks			*before;
}							t_blocks;

typedef struct				s_pages
{
	t_blocks				*blocks;
	size_t					size;
	struct s_pages			*next;
	struct s_pages			*before;
}							t_pages;

typedef struct				s_pages_allocated
{
	t_pages					*tiny_page;
	t_pages					*small_page;
	t_pages					*large_page;
}							t_pages_allocated;

extern t_pages_allocated	g_pages_allocated;

/* internal function to librairy */
void						*allocate_page(t_pages **page, size_t type,
		size_t size);
void						*get_allocated_page(t_pages *page, size_t size);
t_pages						*get_main_page_of_block(t_blocks *to_free);
void	put_memory_hexa(size_t adress);
void	read_ptr(void *ptr, size_t size, char *mess);

/*functions of librairy */
void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						show_alloc_mem();
void						*calloc(size_t nmemb, size_t size);
#endif
