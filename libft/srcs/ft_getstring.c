/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:49:38 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:15:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_getchar(char c, t_flag *flag)
{
	char	*p_var;

	if (c == '\0' && flag->field == 1 && flag->min_field > 0)
	{
		if (!(p_var = (char *)ft_memalloc(flag->min_field + 1)))
			return (NULL);
		if (flag->minus == 1)
		{
			p_var[0] = c;
			ft_put_c_instring((p_var + 1), ' ', (flag->min_field - 1));
		}
		else
			ft_put_c_instring(p_var, ' ', (flag->min_field - 1));
		flag->min_field = 0;
		flag->backzero = 1;
	}
	else
	{
		if (!(p_var = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		p_var[0] = c;
		p_var[1] = '\0';
	}
	return (p_var);
}

char		*ft_returnp_var(char *p_var, t_flag *flag)
{
	int		i;

	i = 0;
	if (flag->preci == 0 && flag->min_nb == 0)
	{
		free(p_var);
		return (NULL);
	}
	while (p_var[i])
		++i;
	if (i == flag->min_nb)
		return (p_var);
	free(p_var);
	return (NULL);
}

char		*ft_getstring(char *str)
{
	char	*p_var;

	if (str)
		return (ft_strdup(str));
	if (!(p_var = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	ft_strcpy(p_var, "(null)");
	return (p_var);
}

void		ft_to_upper(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

void		ft_put_c_instring(char *str, char c, int size)
{
	int		i;

	i = 0;
	while (i < size)
		str[i++] = c;
}
