/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:12 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 16:33:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (unsigned char)c)
			return (p_dst + i + 1);
		i++;
	}
	return (NULL);
}
