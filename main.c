
#include "includes/malloc.h"

void		print_pages_and_blocks(t_pages *page, char *type_page)
{
	t_blocks		*block;

	ft_putstr(type_page);
	ft_putstr(":\n");
	while (page)
	{
		block = page->blocks;
		ft_putstr("\x1b[31m page_size = ");
		ft_putnbr(page->size);
		ft_putstr("\x1b[0m\n");
		while (block)
		{
			ft_putstr("\x1b[32m block_size = ");
			ft_putnbr(block->size);
			ft_putstr("; blocks allocated =");
			ft_putnbr(block->allocated);
			ft_putstr("\x1b[0m\n");
			block = block->next;
		}
		ft_putstr("\n\n");
		page = page->next;
	}
	ft_putstr("\n\n");
}

int			main()
{
	/*
	int		*tmp;
	int		*tmp1;
	int		*tmp2;
	int		*tmp3;
	int		*tmp4;

	tmp = ft_malloc(sizeof(int) * 2);
	tmp[0] = 1;
	tmp[1] = 2;

	tmp1 = ft_malloc(sizeof(int) * 2);
	tmp1[0] = 3;
	tmp1[1] = 4;

	tmp2 = ft_malloc(sizeof(int) * 2);
	tmp2[0] = 5;
	tmp2[1] = 6;

	int		i;
	int		nb;

	i = 0;
	nb = 7;
	tmp3 = ft_malloc(sizeof(int) * 100);
	while (i < 100)
	{
		tmp3[i] = nb;
		i += 1;
		nb += 1;
	}

	tmp4 = ft_malloc(sizeof(int) * 1);
	tmp4[0] = 107;
	tmp4[1] = 108;

	printf("tmp[0] = %d, tmp[1] = %d\n", tmp[0], tmp[1]);
	printf("tmp1[0] = %d, tmp1[1] = %d\n", tmp1[0], tmp1[1]);
	printf("tmp2[0] = %d, tmp2[1] = %d\n", tmp2[0], tmp2[1]);
	i = 0;
	while (i < 100)
	{
		printf("tmp3[%d] = %d\n", i, tmp3[i]);
		i += 1;
	}
	printf("tmp4[0] = %d, tmp4[1] = %d\n", tmp4[0], tmp4[1]);
	
	int		*tmp;
	int		i;

	i = 0;
	while (i <= 120)
	{
		tmp = ft_malloc(sizeof(int) * 128);
		i += 1;
	}
	
	*/
	/*
	int	*tmp, *tmp1, *tmp2, *tmp3;

	print_pages_and_blocks();
	tmp = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	tmp1 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	tmp2 = ft_malloc(sizeof(int) * 32);
	print_pages_and_blocks();
	tmp3 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	ft_free(tmp2);
	print_pages_and_blocks();
	tmp2 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	ft_free(tmp);
	print_pages_and_blocks();
	ft_free(tmp1);
	print_pages_and_blocks();

	tmp = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	tmp1 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	tmp2 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	tmp3 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks();
	ft_free(tmp);
	print_pages_and_blocks();
	ft_free(tmp2);
	print_pages_and_blocks();
	ft_free(tmp1);
	print_pages_and_blocks();
	ft_free(tmp3);
	print_pages_and_blocks();
	*/

	//int	*tmp, *tmp1, *tmp2, *tmp4, *tmp5;

	/*
	tmp = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp1 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp2 = ft_malloc(sizeof(int) * 4);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp2);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp1);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp = ft_malloc(sizeof(int) * 2);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp1 = ft_malloc(sizeof(int) * 8);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp2 = ft_malloc(sizeof(int) * 8);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp4 = ft_malloc(sizeof(int) * 512);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp5 = ft_malloc(sizeof(int) * 1024);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp1);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp2);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp4);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp5);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");

	tmp = ft_malloc(sizeof(int) * 1024);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp1 = ft_malloc(sizeof(int) * 1025);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	tmp2 = ft_malloc(sizeof(int) * 1026);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	ft_free(tmp2);
	print_pages_and_blocks(g_pages_allocated.tiny_page, "TINY");
	print_pages_and_blocks(g_pages_allocated.small_page, "SMALL");
	print_pages_and_blocks(g_pages_allocated.large_page, "LARGE");
	*/
	return (0);
}
