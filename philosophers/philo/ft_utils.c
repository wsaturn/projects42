/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:23:47 by wsaturn           #+#    #+#             */
/*   Updated: 2022/01/05 15:42:08 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_timer(int st)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return ((ct.tv_sec * 1000 + ct.tv_usec / 1000) - st);
}

void	ft_sleep(int time)
{
	time_t	start;
	time_t	end;

	start = ft_timer(0);
	end = ft_timer(0) + time;
	while (start < end)
	{
		usleep(500);
		start = ft_timer(0);
	}
}
