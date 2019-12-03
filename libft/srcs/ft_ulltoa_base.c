/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:46:11 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:19:27 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long nb, int type)
{
	int		size_base;
	char	*new_base;
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (type == 5)
		size_base = 8;
	else if (type == 6 || type == 7 || type == 8)
		size_base = 16;
	if (!(new_base = (char*)malloc(sizeof(char) * 65)))
		return (NULL);
	if (nb == 0)
		new_base[i++] = '0';
	while (nb > 0)
	{
		new_base[i++] = base[nb % size_base];
		nb /= size_base;
	}
	new_base[i] = '\0';
	ft_rev(new_base);
	return (new_base);
}
