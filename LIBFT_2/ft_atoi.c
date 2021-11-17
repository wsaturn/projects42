/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:20:59 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/14 17:09:18 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		znak;
	long	chislo;

	i = 0;
	znak = 1;
	chislo = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			znak = znak * (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (chislo < 0)
		{
			if (znak > 0)
				return (-1);
			return (0);
		}
		chislo = (chislo * 10) + (str[i++] - '0');
	}
	return (chislo * znak);
}
