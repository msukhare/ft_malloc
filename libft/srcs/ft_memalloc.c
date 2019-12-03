/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:45:24 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 10:08:02 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

#include <stdlib.h>

void				*ft_memalloc(size_t size)
{
	void			*p_mem;

	if ((p_mem = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(p_mem, size);
	return (p_mem);
}
