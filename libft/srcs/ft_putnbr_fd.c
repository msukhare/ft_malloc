/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:19:51 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/11 15:25:44 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
	}
	while ((temp /= 10) > 0)
		size *= 10;
	while (size > 0)
	{
		ft_putchar_fd((nb / size) + 48, fd);
		nb %= size;
		size /= 10;
	}
}
