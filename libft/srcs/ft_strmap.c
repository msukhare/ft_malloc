/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:06:44 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 11:17:03 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(new_str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
