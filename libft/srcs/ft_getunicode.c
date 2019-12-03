/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:48:56 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:15:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_charunic(wint_t c, t_flag *flag)
{
	char	*p_var;

	if ((c >= 0xd800 && c <= 0xdfff) || c > 0x10FFFF || c < 0)
		return (NULL);
	if (c >= 0 && c <= 255)
	{
		if (!(p_var = ft_getchar(c, flag)))
			return (NULL);
	}
	else if (!(p_var = ft_getuni(c)))
		return (NULL);
	return (p_var);
}

char		*ft_get_stringunic(wchar_t *str, t_flag *flag)
{
	char	*p_var;
	int		i;
	char	*temp;

	i = 0;
	if (!str)
		return (ft_getstring(NULL));
	p_var = (char *)ft_memalloc(1);
	if (flag->preci == 1 && flag->min_nb > 0)
		flag->min_nb = ft_getpreciuni(str, flag->min_nb);
	while (str[i])
	{
		temp = p_var;
		if ((str[i] >= 0xd800 && str[i] <= 0xdfff) || str[i] > 0x10FFFF)
			return (ft_returnp_var(temp, flag));
		if ((str[i] >= 0 && str[i] <= 255))
		{
			if (!(p_var = ft_strjoinfree(p_var, ft_getchar(str[i], flag))))
				return (ft_returnp_var(temp, flag));
		}
		else if (!(p_var = ft_strjoinfree(p_var, ft_getuni((wint_t)str[i]))))
			return (ft_returnp_var(temp, flag));
		i++;
	}
	return (p_var);
}

void		ft_splitbyteuni(char *p_uni, wint_t c, int nb_byte)
{
	int		i;

	i = 0;
	if (nb_byte == 2)
	{
		p_uni[i++] = (0b11000000 | ((c & 0b11111000000) >> 6));
		p_uni[i++] = (0b10000000 | ((c & 0b111111)));
	}
	else if (nb_byte == 3)
	{
		p_uni[i++] = (0b11100000 | ((c & 0b1111000000000000) >> 12));
		p_uni[i++] = (0b10000000 | ((c & 0b111111000000) >> 6));
		p_uni[i++] = (0b10000000 | (c & 0b111111));
	}
	else if (nb_byte == 4)
	{
		p_uni[i++] = (0b11110000 | ((c & 0b111000000000000000000) >> 18));
		p_uni[i++] = (0b10000000 | ((c & 0b111111000000000000) >> 12));
		p_uni[i++] = (0b10000000 | ((c & 0b111111000000) >> 6));
		p_uni[i++] = (0b10000000 | (c & 0b111111));
	}
	p_uni[i] = '\0';
}

char		*ft_getuni(wint_t c)
{
	char	p_uni[5];
	int		i;

	i = 0;
	if (c == 0)
		p_uni[i++] = '\0';
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
		ft_splitbyteuni(p_uni, c, 2);
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
		ft_splitbyteuni(p_uni, c, 3);
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
		ft_splitbyteuni(p_uni, c, 4);
	else
		return (NULL);
	return (ft_strdup(p_uni));
}
