/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:14:55 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 12:37:40 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*p_str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(p_str = (char*)malloc(sizeof(char) * ((int)(ft_strlen(s) + 1)))))
		return (NULL);
	while (s[i])
	{
		p_str[i] = f(i, s[i]);
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
