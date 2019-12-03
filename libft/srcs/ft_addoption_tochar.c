/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addoption_tochar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:34:50 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:14:25 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checkvar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char		*ft_putdiez(char *p_var, t_flag *flag)
{
	char	*p_diez;
	char	*new_var;
	int		size;

	size = ft_strlen(p_var);
	if (flag->min_nb == size && flag->type == 5)
		return (p_var);
	if (size <= 1 && (flag->type == 8 || flag->type == 7))
		return (p_var);
	if (flag->type != 6 && ft_checkvar(p_var) == 1 && flag->type == 5)
		return (p_var);
	if (flag->type == 5)
		p_diez = "0";
	else if (flag->type == 7 || flag->type == 8 || flag->type == 6)
		p_diez = "0x";
	if (!(new_var = ft_strjoin(p_diez, p_var)))
		return (NULL);
	free(p_var);
	return (new_var);
}

char		*ft_putpreci(char *p_var, t_flag *flag)
{
	char	*new_pvar;
	int		size_char;

	size_char = ft_strlen(p_var);
	if (flag->type == 1 && p_var[0] == '-')
		size_char--;
	new_pvar = p_var;
	if (p_var[0] == '0' && flag->min_nb == 0 && size_char == 1)
		new_pvar[0] = '\0';
	else if (flag->type != 2 && flag->min_nb > size_char)
	{
		new_pvar = ft_addzero(p_var, flag, size_char);
		if (flag->type == 1 && flag->conv != 6 && new_pvar)
			ft_movesigne(new_pvar);
	}
	else if (flag->type == 2 && flag->min_nb < size_char)
		new_pvar = ft_cutstring(p_var, flag->min_nb);
	if (new_pvar && flag->type == 5 && new_pvar[0] == '\0' &&
			flag->min_nb == 0 && flag->diez == 1)
	{
		flag->diez = 0;
		new_pvar[0] = '0';
	}
	return (new_pvar);
}

char		*ft_putfieldleft(char *p_field, char *p_var, t_flag *flag)
{
	char	*new_pvar;

	if (!(new_pvar = ft_strjoinfree(p_field, p_var)))
		return (NULL);
	if ((flag->type == 8 || flag->type == 7) && flag->diez == 1 &&
			!ft_checkvar(new_pvar) && flag->zero == 1)
		ft_mvdiez(new_pvar, flag->min_field);
	return (new_pvar);
}

char		*ft_putfield(char *p_var, t_flag *flag)
{
	char	*new_pvar;
	char	*p_field;
	int		size;

	size = ft_strlen(p_var);
	if (!(p_field = (char*)ft_memalloc(flag->min_field + 1)))
		return (NULL);
	if (flag->zero == 1 && flag->type != 2 && flag->type != 3 &&
			(flag->preci == 0 || flag->pourcent == 1) && flag->minus == 0)
		ft_put_c_instring(p_field, '0', (flag->min_field - size));
	else
		ft_put_c_instring(p_field, ' ', (flag->min_field - size));
	if (flag->minus == 1)
	{
		if (!(new_pvar = ft_strjoinfree(p_var, p_field)))
			return (NULL);
	}
	else
	{
		if (!(new_pvar = ft_putfieldleft(p_field, p_var, flag)))
			return (NULL);
	}
	(flag->type == 1 && flag->conv != 6 && flag->zero == 1 && flag->preci == 0)\
		? ft_movesigne(new_pvar) : 0;
	return (new_pvar);
}
