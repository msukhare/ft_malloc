/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:16:48 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 10:28:15 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*p_str;

	i = 0;
	if (!(p_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		p_str[i] = '\0';
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
