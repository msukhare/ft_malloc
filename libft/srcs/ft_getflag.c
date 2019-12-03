/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 08:36:19 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:15:02 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	*ft_createlem(void)
{
	t_flag		*new_flag;

	new_flag = NULL;
	if (!(new_flag = (t_flag *)malloc(sizeof(t_flag) * 1)))
		return (NULL);
	new_flag->type = 0;
	new_flag->conv = 0;
	new_flag->minus = 0;
	new_flag->signe = 0;
	new_flag->diez = 0;
	new_flag->space = 0;
	new_flag->zero = 0;
	new_flag->min_nb = 0;
	new_flag->min_field = 0;
	new_flag->preci = 0;
	new_flag->field = 0;
	new_flag->pourcent = 0;
	new_flag->backzero = 0;
	new_flag->p_var = NULL;
	return (new_flag);
}

static int		ft_stopflag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

static void		ft_initflag(char *p_flag, t_flag *flag)
{
	int			i;

	i = 0;
	while (p_flag[i])
	{
		if (p_flag[i] == '#' || p_flag[i] == '0' || p_flag[i] == '+' ||
			p_flag[i] == '-' || p_flag[i] == ' ' || p_flag[i] == '.')
			ft_checksigne(p_flag, &i, flag);
		else if (p_flag[i] >= '1' && p_flag[i] <= '9')
			ft_checkfield(p_flag, &i, flag);
		else if (p_flag[i] == 'h' || p_flag[i] == 'j' ||
			p_flag[i] == 'z' || p_flag[i] == 'l')
			ft_checkconv(p_flag, &i, flag);
		else if (ft_stopflag(p_flag[i]))
			ft_checktype(p_flag[i], flag);
		i++;
	}
}

t_flag			*ft_getflag(const char *str, int *i)
{
	t_flag		*flag;
	int			j;
	char		*p_flag;

	j = (*i + 1);
	while (str[j] && !(ft_stopflag(str[j])))
		j++;
	if (!(p_flag = (char *)malloc(sizeof(char) * ((j - (*i)) + 1))))
		return (NULL);
	j = 0;
	(*i)++;
	while (str[(*i)] && !(ft_stopflag(str[(*i)])))
	{
		p_flag[j] = str[(*i)];
		j++;
		(*i)++;
	}
	if (str[(*i)] != '\0')
		p_flag[j++] = str[(*i)++];
	p_flag[j] = '\0';
	if (!(flag = ft_createlem()))
		return (NULL);
	ft_initflag(p_flag, flag);
	free(p_flag);
	return (flag);
}
