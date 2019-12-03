/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:46:09 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 09:27:55 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	while (s2[i])
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
