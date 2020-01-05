/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:43:45 by msukhare          #+#    #+#             */
/*   Updated: 2020/01/05 14:04:23 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
	void	*to_ret;

	//ft_putstr("calloc call\n");
	if (nmemb == 0 || size == 0)
	{
		//ft_putstr("return NULL\n");
		return (NULL);
	}
	if (!(to_ret = malloc(nmemb * size)))
	{
		//ft_putstr("return NULL\n");
		return (NULL);
	}
	ft_bzero(to_ret, nmemb * size);
	//ft_putstr("return calloced ptr\n");
	return (to_ret);
}
