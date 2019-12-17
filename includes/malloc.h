/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:47:03 by msukhare          #+#    #+#             */
/*   Updated: 2019/12/17 19:31:29 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdio.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>
# include "../libft/include/libft.h"

/* define all page size available */

# define TINY 512
# define SMALL 2048

# define ALIGNEMENT 16

# define PROTECTION (PROT_READ | PROT_WRITE)
# define FLAGS (MAP_ANONYMOUS | MAP_SHARED)

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

/*functions of librairy */
void						ft_free(void *ptr);
void						*ft_malloc(size_t size);
//void						*realloc(void *ptr, size_t size);
void						show_alloc_mem();
#endif
