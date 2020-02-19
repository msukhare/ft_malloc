/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:43:45 by msukhare          #+#    #+#             */
/*   Updated: 2020/01/12 19:34:00 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
	void	*to_ret;

	if (nmemb == 0 || size == 0 || !(to_ret = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(to_ret, nmemb * size);
	return (to_ret);
}
