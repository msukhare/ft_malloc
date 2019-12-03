/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 08:38:03 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:20:09 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_checksigne(char *str, int *i, t_flag *flag)
{
	if (str[*i] == '-' && flag->minus == 0)
		flag->minus = 1;
	else if (str[*i] == '+' && flag->signe == 0)
		flag->signe = 1;
	else if (str[*i] == '#' && flag->diez == 0)
		flag->diez = 1;
	else if (str[*i] == ' ' && flag->space == 0)
		flag->space = 1;
	else if (str[*i] == '0' && flag->zero == 0)
		flag->zero = 1;
	else if (str[*i] == '.')
	{
		flag->preci = 1;
		(*i)++;
		flag->min_nb = ft_atoi((str + (*i)));
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		(*i)--;
	}
}

void	ft_checkfield(char *str, int *i, t_flag *flag)
{
	if ((flag->min_field = ft_atoi(str + (*i))) > 0)
		flag->field = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	(*i)--;
}

void	ft_checkconv(char *p_flag, int *i, t_flag *flag)
{
	if (p_flag[*i] == 'l' && p_flag[(*i) + 1] == 'l')
	{
		flag->conv = 4;
		(*i)++;
	}
	else if (p_flag[*i] == 'h' && p_flag[(*i) + 1] == 'h')
	{
		flag->conv = 1;
		(*i)++;
	}
	else if (p_flag[*i] == 'l')
		flag->conv = 3;
	else if (p_flag[*i] == 'h')
		flag->conv = 2;
	else if (p_flag[*i] == 'j')
		flag->conv = 5;
	else if (p_flag[*i] == 'z')
		flag->conv = 6;
}

void	ft_checktype(char c, t_flag *flag)
{
	if (c == 'U' || c == 'D' || c == 'O' || c == 'C' || c == 'S')
		flag->conv = 3;
	if (c == '%')
		flag->pourcent = 1;
	else if (c == 'i' || c == 'd' || c == 'D')
		flag->type = 1;
	else if (c == 's' || c == 'S')
		flag->type = 2;
	else if (c == 'c' || c == 'C')
		flag->type = 3;
	else if (c == 'u' || c == 'U')
		flag->type = 4;
	else if (c == 'o' || c == 'O')
		flag->type = 5;
	else if (c == 'p')
		flag->type = 6;
	else if (c == 'x')
		flag->type = 7;
	else if (c == 'X')
		flag->type = 8;
}
