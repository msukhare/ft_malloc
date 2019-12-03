/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:36:31 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/11 14:41:43 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long	size;
	long	temp;
	long	nb;

	size = 1;
	temp = n;
	nb = n;
	if (n < 0)
	{
		temp *= -1;
		nb *= -1;
		ft_putchar('-');
	}
	while ((temp /= 10) > 0)
		size *= 10;
	while (size > 0)
	{
		ft_putchar((nb / size) + 48);
		nb %= size;
		size /= 10;
	}
}
