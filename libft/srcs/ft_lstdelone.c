/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:12:39 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 12:41:25 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	if (!*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
