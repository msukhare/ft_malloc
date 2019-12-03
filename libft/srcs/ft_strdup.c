/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:31:36 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/11 16:13:48 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*new_char;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(new_char = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		new_char[i] = s1[i];
		i++;
	}
	new_char[i] = '\0';
	return (new_char);
}
