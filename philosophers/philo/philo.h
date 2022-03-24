/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:24:06 by wsaturn           #+#    #+#             */
/*   Updated: 2022/01/05 15:44:51 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define DEATH "died"
# define FORK "has taken a fork"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define THINK "is thinking"

typedef struct s_ph
{
	int				number;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				eat_rnd;
	int				start_time;
	int				eat_now;
	pthread_mutex_t	message;
}				t_ph;

typedef struct s_args
{
	pthread_t		tid;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	t_change_eat;
	t_ph			*ph;
	int				id;
	int				last_eat;
}				t_args;

int		ft_atoi(const char *str);
int		ft_ph_init(int ac, char **av, t_ph *ph);
int		ft_init_threads(t_args *args);
int		ft_timer(int st);
void	ft_sleep(int time);
int		ft_status(char *status, t_args *args, int leet);
void	*ft_eat(void *args_);
void	*ft_death(void *args_);
void	ft_cleaner(t_args *args, pthread_mutex_t *fork, t_ph ph);

#endif
