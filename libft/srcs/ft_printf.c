/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:56:51 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:18:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkflag(const char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_getsizebefore(const char *str, int i, int j, char *buff)
{
	while (str[i] != '%' && i >= 1)
		i--;
	if (i >= 1 && j >= 1)
	{
		--i;
		--j;
	}
	while (str[i] && buff[j] && str[i] == buff[j] &&
			(str[i] != '%' || buff[j] != '%'))
	{
		--i;
		--j;
	}
	return (j + 1);
}

static int		ft_strvar(const char *str, va_list ap, char *buff)
{
	int			i;
	int			j;
	int			size;
	t_flag		*flag;

	i = 0;
	j = 0;
	size = 0;
	while (str[i])
	{
		size += ft_putinbuff(str, &i, &j, buff);
		if (str[i] == '%')
		{
			if (!(flag = ft_getflag(str, &i)) ||
					!(flag->p_var = ft_newvar(ap, flag)))
			{
				(flag) ? free(flag) : 0;
				write(1, buff, ft_getsizebefore(str, i, j, buff));
				return (-1);
			}
			size += ft_putinbuffvar(flag, &j, buff);
		}
	}
	return (size += write(1, buff, j));
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	static int	ret;
	char		buff[BUFF_SIZE];

	if (!ft_checkflag(str))
		return (write(1, str, ft_strlen(str)));
	ft_bzero(buff, BUFF_SIZE + 1);
	va_start(ap, str);
	if (ret == -1)
		ft_strvar(str, ap, buff);
	else
		ret = ft_strvar(str, ap, buff);
	va_end(ap);
	return (ret);
}
