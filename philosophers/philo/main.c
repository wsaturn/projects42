/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:23:55 by wsaturn           #+#    #+#             */
/*   Updated: 2022/01/05 15:42:33 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleaner(t_args *args, pthread_mutex_t *fork, t_ph ph)
{
	int	i;

	i = -1;
	while (++i < ph.number)
	{
		pthread_mutex_destroy(&args[i].t_change_eat);
		pthread_mutex_unlock(&fork[i]);
		pthread_mutex_destroy(&fork[i]);
	}
	pthread_mutex_unlock(&ph.message);
	pthread_mutex_destroy(&ph.message);
	free(fork);
	free(args);
}

pthread_mutex_t	*ft_init_forks(t_ph ph, t_args *args)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * ph.number);
	if (!fork)
		write(2, "Error: Wrong fork initiation\n", 30);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < ph.number)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < ph.number - 1)
	{
		args[i].left = &fork[i];
		args[i].right = &fork[i + 1];
		i++;
	}
	args[i].left = &fork[i];
	args[i].right = &fork[0];
	return (fork);
}

t_args	*ft_init_philos(t_ph *ph)
{
	t_args	*args;
	int		i;

	args = malloc(sizeof(t_args) * ph->number);
	if (!args)
	{
		write(2, "Error: Wrong philosophers initianion\n", 38);
		return (NULL);
	}
	i = -1;
	while (++i < ph->number)
	{
		args[i].id = i + 1;
		args[i].last_eat = 0;
		args[i].ph = ph;
		pthread_mutex_init(&args[i].t_change_eat, NULL);
	}
	return (args);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	*fork;
	t_ph			ph;
	t_args			*args;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error: Arguments number problem\n", 33);
		return (1);
	}
	if (ft_ph_init(ac, av, &ph))
	{
		write(2, "Error: Invalid Argument or wrong value\n", 40);
		return (1);
	}
	args = ft_init_philos(&ph);
	fork = ft_init_forks(ph, args);
	if (ft_init_threads(args))
		return (printf("Error: Wrong thread creation"));
	ft_cleaner(args, fork, ph);
	return (0);
}
