/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:11:17 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/02 21:12:05 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int		i;
	int		znak;
	long	chislo;

	i = 0;
	znak = 1;
	chislo = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			znak = znak * (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (chislo < 0)
		{
			if (znak > 0)
				return (-1);
			return (0);
		}
		chislo = (chislo * 10) + (s[i++] - '0');
	}
	return (chislo * znak);
}
