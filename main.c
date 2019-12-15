
#include "includes/malloc.h"

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
	*/
	int		*tmp;
	int		i;

	i = 0;
	while (i <= 112)
	{
		tmp = ft_malloc(sizeof(int) * 128);
		i += 1;
	}
	return (0);
}
