/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:50:12 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 09:28:30 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
