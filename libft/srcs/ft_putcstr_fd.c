/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:29:43 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/20 12:30:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putcstr_fd(char *str, int fd, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		write(fd, &str[i], 1);
		i++;
	}
}