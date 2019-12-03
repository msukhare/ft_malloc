/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:16:36 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:19:06 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	if (!(new_str = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	free(s2);
	return (new_str);
}
