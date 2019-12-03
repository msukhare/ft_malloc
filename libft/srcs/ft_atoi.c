/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:13:57 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/10 09:34:41 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == 32)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			nb;
	int			i;
	int			neg;

	nb = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	return (nb * neg);
}
