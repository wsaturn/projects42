/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:31:15 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:33:02 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_twin(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sym(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && !ft_isdigit(str[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((ft_atoi(str[i]) > 2147483647)
			|| (ft_atoi(str[i]) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}
