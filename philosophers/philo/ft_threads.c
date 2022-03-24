/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:23:41 by wsaturn           #+#    #+#             */
/*   Updated: 2022/01/05 15:41:23 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_die(t_args *args, t_ph *ph)
{
	if (ft_timer(ph->start_time) - args->last_eat > ph->t_to_die)
	{
		ft_status(DEATH, args, 0);
		return (1);
	}
	return (0);
}

void	*ft_death(void *args_)
{
	t_args	*args;
	t_ph	*ph;
	int		i;

	args = args_;
	ph = args->ph;
	while (1)
	{
		i = -1;
		while (++i < ph->number)
		{
			pthread_mutex_lock(&args[i].t_change_eat);
			if (ft_die(&args[i], ph))
				return ((void *)1);
			if (ph->eat_now >= ph->eat_rnd * ph->number && ph->eat_rnd > 0)
			{
				pthread_mutex_lock(&args->ph->message);
				return ((void *)1);
			}
			pthread_mutex_unlock(&args[i].t_change_eat);
		}
	}
	return ((void *)0);
}

void	*ft_eat(void *args_)
{
	t_args	*args;

	args = (t_args *)args_;
	if (args->id % 2 == 0)
		ft_sleep(args->ph->t_to_eat);
	while (1)
	{
		pthread_mutex_lock(args->left);
		ft_status(FORK, args, 1);
		pthread_mutex_lock(args->right);
		ft_status(FORK, args, 1);
		pthread_mutex_lock(&args->t_change_eat);
		ft_status(EAT, args, 1);
		args->last_eat = ft_timer(args->ph->start_time);
		args->ph->eat_now += 1;
		pthread_mutex_unlock(&args->t_change_eat);
		ft_sleep(args->ph->t_to_eat);
		ft_status(SLEEP, args, 1);
		pthread_mutex_unlock(args->left);
		pthread_mutex_unlock(args->right);
		ft_sleep(args->ph->t_to_sleep);
		ft_status(THINK, args, 1);
	}
	return ((void *)0);
}

int	ft_init_threads(t_args *args)
{
	pthread_t	tid;
	int			i;

	i = 0;
	if (pthread_create(&tid, NULL, ft_death, (void *)args))
		return (1);
	while (i < args[i].ph->number - 1)
	{
		if (pthread_create(&args[i].tid, NULL, ft_eat, (void *)&args[i]))
			return (1);
		pthread_detach(args[i].tid);
		i++;
	}
	if (pthread_create(&args->tid, NULL, ft_eat, (void *)&args[i]))
		return (1);
	pthread_join(tid, NULL);
	return (0);
}
