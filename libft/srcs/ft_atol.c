/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:42:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/19 13:27:22 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == 32)
		return (1);
	return (0);
}

long			ft_atol(const char *str)
{
	long		nb;
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
