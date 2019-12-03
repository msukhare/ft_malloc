/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:21:47 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:14:13 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_getpreciuni(wchar_t *str, int preci)
{
	int			i;
	int			size;
	int			temp;

	i = 0;
	size = 0;
	while (str[i] && size < preci)
	{
		temp = 0;
		if (str[i] <= 255)
			temp++;
		else if (str[i] <= 0x7ff)
			temp += 2;
		else if (str[i] <= 0xffff)
			temp += 3;
		else if (str[i] <= 0x10fffff)
			temp += 4;
		else
			return (size);
		if ((size + temp) <= preci)
			size += temp;
		i++;
	}
	return (size);
}

char			*ft_addzero(char *p_var, t_flag *flag, int size_char)
{
	int			i;
	char		*p_zero;
	char		*new_pvar;

	i = 0;
	if (flag->diez == 1 && flag->type == 5 && size_char > 1)
		size_char++;
	if (!(p_zero = (char *)malloc(sizeof(char) *\
					((flag->min_nb - size_char) + 1))))
		return (NULL);
	while (i < (flag->min_nb - size_char))
		p_zero[i++] = '0';
	p_zero[i] = '\0';
	if (!(new_pvar = ft_strjoinfree(p_zero, p_var)))
		return (NULL);
	return (new_pvar);
}

char			*ft_cutstring(char *p_var, int preci)
{
	int			i;
	char		*new_pvar;

	i = 0;
	if (!(new_pvar = (char*)malloc(sizeof(char) * (preci + 1))))
		return (NULL);
	while (i < preci && p_var[i])
	{
		new_pvar[i] = p_var[i];
		i++;
	}
	new_pvar[i] = '\0';
	free(p_var);
	return (new_pvar);
}
