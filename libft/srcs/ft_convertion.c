/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:27:11 by msukhare          #+#    #+#             */
/*   Updated: 2018/01/31 16:14:41 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_convert_integ(va_list ap, t_flag *flag)
{
	char	*p_var;

	p_var = NULL;
	if (flag->conv == 1)
		p_var = ft_lltoa((char)va_arg(ap, long long));
	else if (flag->conv == 2)
		p_var = ft_lltoa((short int)va_arg(ap, long long));
	else if (flag->conv == 3)
		p_var = ft_lltoa((long int)va_arg(ap, long long));
	else if (flag->conv == 4)
		p_var = ft_lltoa(va_arg(ap, long long int));
	else if (flag->conv == 5)
		p_var = ft_lltoa(va_arg(ap, intmax_t));
	else if (flag->conv == 6)
		p_var = ft_lltoa((size_t)va_arg(ap, long long));
	return (p_var);
}

static char	*ft_convertunic(va_list ap, t_flag *flag)
{
	char	*p_var;

	p_var = NULL;
	if (flag->type == 2)
		p_var = ft_get_stringunic(va_arg(ap, wchar_t*), flag);
	else if (flag->type == 3)
		p_var = ft_get_charunic(va_arg(ap, wint_t), flag);
	return (p_var);
}

static char	*ft_convertu(va_list ap, t_flag *flag)
{
	char	*p_var;

	p_var = NULL;
	if (flag->conv == 1)
		p_var = ft_ulltoa((unsigned char)va_arg(ap, unsigned long long));
	else if (flag->conv == 2)
		p_var = ft_ulltoa((unsigned short int)va_arg(ap, unsigned long long));
	else if (flag->conv == 3)
		p_var = ft_ulltoa((unsigned long int)va_arg(ap, unsigned long long));
	else if (flag->conv == 4)
		p_var = ft_ulltoa(va_arg(ap, unsigned long long int));
	else if (flag->conv == 5)
		p_var = ft_ulltoa(va_arg(ap, uintmax_t));
	else if (flag->conv == 6)
		p_var = ft_ulltoa((unsigned long long)va_arg(ap, unsigned long long));
	return (p_var);
}

static char	*ft_converthexoct(va_list ap, t_flag *flag)
{
	char	*p_var;

	p_var = NULL;
	if (flag->conv == 1)
		p_var = ft_ulltoa_base((unsigned char)va_arg(ap, unsigned long),\
				flag->type);
	else if (flag->conv == 2)
		p_var = ft_ulltoa_base((unsigned short)va_arg(ap, unsigned long long),\
				flag->type);
	else if (flag->conv == 3)
		p_var = ft_ulltoa_base(\
				(unsigned long int)va_arg(ap, unsigned long long), flag->type);
	else if (flag->conv == 4)
		p_var = ft_ulltoa_base(va_arg(ap, unsigned long long int),\
				flag->type);
	else if (flag->conv == 5)
		p_var = ft_ulltoa_base(va_arg(ap, uintmax_t), flag->type);
	else if (flag->conv == 6)
		p_var = ft_ulltoa_base((size_t)va_arg(ap, unsigned long long),\
				flag->type);
	return (p_var);
}

char		*ft_get_convertion(va_list ap, t_flag *flag)
{
	char	*p_var;

	p_var = NULL;
	if (flag->type == 1)
		p_var = ft_get_convert_integ(ap, flag);
	else if (flag->type == 4)
		p_var = ft_convertu(ap, flag);
	else if ((flag->type == 2 || flag->type == 3) && flag->conv == 3)
		p_var = ft_convertunic(ap, flag);
	else if (flag->type == 5 || flag->type == 7 || flag->type == 8)
		p_var = ft_converthexoct(ap, flag);
	return (p_var);
}
