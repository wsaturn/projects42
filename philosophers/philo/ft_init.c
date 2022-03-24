/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:23:34 by wsaturn           #+#    #+#             */
/*   Updated: 2022/01/05 15:40:41 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_my_cmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

static int	ft_dig(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_ph_init(int ac, char **av, t_ph *ph)
{
	if (ft_dig(av[1]) || ft_dig(av[2]) || ft_dig(av[3]) || ft_dig(av[4]))
		return (1);
	ph->number = ft_atoi(av[1]);
	ph->t_to_die = ft_atoi(av[2]);
	ph->t_to_eat = ft_atoi(av[3]);
	ph->t_to_sleep = ft_atoi(av[4]);
	ph->eat_rnd = -1;
	ph->eat_now = 0;
	ph->start_time = ft_timer(0);
	if (ac == 6)
	{
		if (ft_dig(av[5]))
			return (1);
		ph->eat_rnd = ft_atoi(av[5]);
	}
	if (ph->number == 0 || ph->eat_rnd == 0)
		return (1);
	if ((ph->number < 1 || ph->number > 200 || ph->t_to_die < 1)
		|| ph->t_to_eat < 60 || ph->t_to_sleep < 60 || ph->eat_rnd < -1)
		return (1);
	if (pthread_mutex_init(&ph->message, NULL))
		return (1);
	return (0);
}

int	ft_status(char *status, t_args *args, int leet)
{
	static int	is_end = 0;
	int			time;

	if (args == NULL)
	{
		printf("%s\n", status);
		return (1);
	}
	time = args->ph->start_time;
	pthread_mutex_lock(&args->ph->message);
	if (!is_end)
	{
		printf("%d ", ft_timer(time));
		printf("%d %s\n", args->id, status);
		if (ft_my_cmp(status, DEATH))
			is_end = 1;
	}
	if (leet)
		pthread_mutex_unlock(&args->ph->message);
	return (0);
}
