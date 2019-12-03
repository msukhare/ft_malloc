/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:13:08 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/25 16:04:19 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strccmp(char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] != c || s2[i] != c))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}