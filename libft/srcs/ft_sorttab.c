/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:28:58 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/27 12:56:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_sorttab(int *tab_int, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min;
	int		temp;

	i = 0;
	while (i < len)
	{
		j = i;
		min = i;
		while (j < len)
		{
			if (tab_int[j] < tab_int[min])
				min = j;
			j++;
		}
		temp = tab_int[min];
		tab_int[min] = tab_int[i];
		tab_int[i] = temp;
		i++;
	}
}
