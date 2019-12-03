/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:15:52 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 09:20:04 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	unsigned char	p_temp[len];
	size_t			i;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	i = 0;
	if (len >= (1024 * 1024 * 128))
		return (NULL);
	while (i < len)
	{
		p_temp[i] = p_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		p_dst[i] = p_temp[i];
		i++;
	}
	return (dst);
}
