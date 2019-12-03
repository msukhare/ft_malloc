/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:48:17 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 16:54:07 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rev(char *s1)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = (int)(ft_strlen(s1) - 1);
	while (i < size)
	{
		temp = s1[i];
		s1[i] = s1[size];
		s1[size] = temp;
		i++;
		size--;
	}
}
