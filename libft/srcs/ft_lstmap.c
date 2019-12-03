/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:35:04 by msukhare          #+#    #+#             */
/*   Updated: 2017/12/04 11:45:12 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*begin_list;
	t_list	*new_ele;
	t_list	*help;

	if (!lst || !f)
		return (NULL);
	help = f(lst);
	if (!(begin_list = ft_lstnew(help->content, help->content_size)))
		return (NULL);
	lst = lst->next;
	new_ele = begin_list;
	while (lst)
	{
		help = f(lst);
		if (!(new_ele->next = ft_lstnew(help->content, help->content_size)))
			return (NULL);
		lst = lst->next;
		new_ele = new_ele->next;
	}
	return (begin_list);
}
