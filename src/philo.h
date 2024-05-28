/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:43:02 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 16:51:29 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				state;
}			t_mutex;

typedef struct s_philo
{
	int		num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start_time;
	int		number_of_times_each_philosopher_must_eat;
	int		max_eat;
	int		dead;
	t_mutex	*mutex;
}			t_philo;

typedef struct s_tid
{
	long int	time_stamp;
	long int	last_eat;
	long int	check_eat;
	int			eat;
	t_philo		*philo;
	int			*id;
}			t_tid;


/**********LIB************/

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strerror(char *str);
int			str_digit(char *str);
void		ft_putnbr_long(long int nb);
void		ft_putnbr(int nb);
void		ft_put_msg(char *str, t_tid *philo);

/*************PHILO***********/

t_philo 	*get_philos(t_philo *philo);
void		*ft_create_philo(void *id);
int			ft_life(t_tid *philo);
int			ft_eat(t_tid *philo);
int			ft_dead(t_tid *philo);
int			ft_fork(t_tid *philo);
long int	get_time(void);

/*************LOCK AND UNLOCK********/

void		ft_unlock_mutex(t_tid *philo);
void		ft_lock_mutex(int id, t_tid *philo);

#endif