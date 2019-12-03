/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:31:20 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:18:09 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_movespace(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == ' ')
	{
		str[i] = '0';
		str[0] = ' ';
	}
}

static char	*ft_putoption(char *p_var, t_flag *flag)
{
	char	*new_char;

	new_char = p_var;
	if (flag->preci == 1 && flag->type != 3 && flag->pourcent != 1)
		new_char = ft_putpreci(new_char, flag);
	if (flag->signe == 1 && flag->type == 1 && flag->conv != 6)
		new_char = ft_addsigne(new_char);
	if (flag->diez == 1 && (flag->type == 5 || flag->type == 7 ||
		flag->type == 8))
		new_char = ft_putdiez(new_char, flag);
	if (flag->space == 1 && flag->signe == 0 && flag->type == 1 &&
		flag->conv != 6)
		new_char = ft_addspace(new_char);
	if (flag->field == 1 && flag->min_field > 0)
		new_char = ft_putfield(new_char, flag);
	if (flag->field == 1 && flag->space == 1 && flag->zero == 1)
		ft_movespace(new_char);
	if (flag->type == 8)
		ft_to_upper(new_char);
	return (new_char);
}

static char	*ft_getvar(va_list ap, t_flag *flag)
{
	if (flag->type == 1)
		return (ft_lltoa(va_arg(ap, int)));
	else if (flag->type == 2)
		return (ft_getstring(va_arg(ap, char*)));
	else if (flag->type == 3)
		return (ft_getchar(va_arg(ap, int), flag));
	else if (flag->type == 4)
		return (ft_lltoa(va_arg(ap, unsigned int)));
	else if (flag->type == 5)
		return (ft_ulltoa_base(va_arg(ap, unsigned int), flag->type));
	else if (flag->type == 6)
		return (ft_putdiez(ft_ulltoa_base(va_arg(ap, unsigned long long),\
					flag->type), flag));
	else if (flag->type == 7 || flag->type == 8)
		return (ft_ulltoa_base(va_arg(ap, unsigned int), flag->type));
	return (NULL);
}

char		*ft_newvar(va_list ap, t_flag *flag)
{
	char	*p_var;
	char	*temp;

	if (!(p_var = (char *)ft_memalloc(1)))
		return (NULL);
	temp = p_var;
	if (flag->conv > 0 && ((flag->type >= 1 && flag->type <= 5) ||
			flag->type == 7 || flag->type == 8))
		p_var = ft_get_convertion(ap, flag);
	else if (flag->pourcent == 1)
		p_var = ft_getchar('%', flag);
	else if (flag->type >= 1 && flag->type <= 8)
		p_var = ft_getvar(ap, flag);
	else
		return (p_var);
	free(temp);
	if (p_var)
		p_var = ft_putoption(p_var, flag);
	return (p_var);
}
