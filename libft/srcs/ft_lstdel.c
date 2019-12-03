/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:07:00 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 12:41:41 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*temp;
	t_list	*to_sup;

	if (!alst)
		return ;
	temp = *alst;
	while (temp)
	{
		to_sup = temp;
		temp = temp->next;
		del(to_sup->content, to_sup->content_size);
		free(to_sup);
	}
	*alst = NULL;
}
