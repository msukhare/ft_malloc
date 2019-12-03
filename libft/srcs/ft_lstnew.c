/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:53:06 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 15:06:04 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_ele;

	if (!(new_ele = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_ele->content = NULL;
		new_ele->content_size = 0;
	}
	else
	{
		if (!(new_ele->content = malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(new_ele->content, content, content_size);
		new_ele->content_size = content_size;
	}
	new_ele->next = NULL;
	return (new_ele);
}
