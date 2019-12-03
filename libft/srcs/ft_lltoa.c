/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:27 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:16:59 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_recupsize(long long n, unsigned long long *size,\
		int *neg)
{
	int					i;
	char				*p_str;
	unsigned long long	temp;

	i = 0;
	*size = 1;
	temp = n;
	if (n < 0)
	{
		i++;
		*neg = 1;
		temp *= -1;
	}
	if (n == 0)
		i++;
	while (temp > 0)
	{
		i++;
		temp /= 10;
		(*size) *= 10;
	}
	if (!(p_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (p_str);
}

char					*ft_lltoa(long long n)
{
	char				*str;
	int					i;
	unsigned long long	size;
	int					neg;
	unsigned long long	temp;

	i = 0;
	neg = 0;
	temp = n;
	if (!(str = ft_recupsize(n, &size, &neg)))
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if (neg == 1)
	{
		str[i++] = '-';
		temp *= -1;
	}
	while ((size /= 10) > 0)
	{
		str[i++] = ((temp / size) + 48);
		temp %= size;
	}
	str[i] = '\0';
	return (str);
}
