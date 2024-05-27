/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:43:02 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/27 17:46:20 by hulefevr         ###   ########.fr       */
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
	t_mutex	*mutex;
}			t_philo;

typedef struct s_tid
{
	long int	time_stamp;
	int			eat;
	t_philo		*philo;
	int			*id;
}			t_tid;


/**********LIB************/

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strerror(char *str);
int			str_digit(char *str);

/*************PHILO***********/

t_philo 	*get_philos(t_philo *philo);
void		*ft_create_philo(void *id);

#endif