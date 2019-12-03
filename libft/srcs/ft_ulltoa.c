/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:27 by msukhare          #+#    #+#             */
/*   Updated: 2017/12/25 14:11:11 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <stdlib.h>

static char				*ft_recupsize(unsigned long long n, \
		unsigned long long *size)
{
	int					i;
	char				*p_str;

	i = 0;
	*size = 1;
	if (n == 0)
		i++;
	while ((n /= 10) > 0)
	{
		i++;
		(*size) *= 10;
	}
	if (!(p_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (p_str);
}

char					*ft_ulltoa(unsigned long long n)
{
	char				*str;
	int					i;
	unsigned long long	size;

	i = 0;
	if (!(str = ft_recupsize(n, &size)))
		return (NULL);
	while (size > 0)
	{
		str[i++] = ((n / size) + 48);
		n %= size;
		size /= 10;
	}
	str[i] = '\0';
	return (str);
}
