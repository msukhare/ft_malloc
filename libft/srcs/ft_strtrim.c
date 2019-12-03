/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:50:34 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:39 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <string.h>

static int			ft_isspace(int c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int			ft_checkafter(char const *str)
{
	int				i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int			ft_count_whitoutsp(char const *s)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i] && !ft_checkafter((s + i)))
	{
		i++;
		j++;
	}
	return (j);
}

char				*ft_strtrim(char const *s)
{
	int				i;
	int				j;
	char			*new_str;

	if (!s)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_count_whitoutsp(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i] && !ft_checkafter((s + i)))
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
