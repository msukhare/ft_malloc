/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managbuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 11:52:35 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:17:28 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writebuff(char *buff, int *j, int *size)
{
	*j = 0;
	*size += write(1, buff, BUFF_SIZE);
	ft_bzero(buff, (BUFF_SIZE));
}

int			ft_putinbuff(const char *str, int *i, int *j, char *buff)
{
	int		size;

	size = 0;
	while (str[*i] != '%' && str[*i])
	{
		buff[(*j)++] = str[(*i)++];
		if (*j >= BUFF_SIZE)
			ft_writebuff(buff, j, &size);
	}
	return (size);
}

int			ft_putinbuffvar(t_flag *flag, int *j, char *buff)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (flag->p_var[0] == '\0' && flag->type == 3)
	{
		i++;
		(*j)++;
	}
	while (flag->p_var[i])
	{
		buff[*j] = flag->p_var[i];
		(*j)++;
		i++;
		if (*j >= BUFF_SIZE)
			ft_writebuff(buff, j, &size);
	}
	if (flag->backzero == 1 && flag->minus == 0)
		(*j)++;
	free(flag->p_var);
	free(flag);
	return (size);
}
