/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:25:11 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/10 12:11:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		i;

	i = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
