/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:27 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 11:43:38 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <stdlib.h>

static char		*ft_recupsize(int n, long *size, int *neg)
{
	int			i;
	long		temp;
	char		*p_str;

	i = 0;
	temp = n;
	*size = 1;
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

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	long		size;
	long		temp;
	int			neg;

	temp = n;
	i = 0;
	neg = 0;
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
