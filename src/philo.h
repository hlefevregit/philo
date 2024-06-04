/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:43:02 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 16:11:49 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_gen	t_gen;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	long int		last_meal;
	t_gen			*gen;
	int				id;
	int				ate;
}				t_philo;

typedef struct s_gen
{
	int				alive;
	int				nbr_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				nbr_meal;
	long int		start_meal;
	t_philo			*philos;
	int				all_ate;
	pthread_mutex_t	print;
}				t_gen;


/**********LIB************/

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr_long(long int nb);
void		ft_putnbr(int nb);
void		ft_put_msg(char *str, t_philo *philo);

int			ft_strerror(char *str);
int			str_digit(char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

/*************PHILO***********/

void		*ft_create_philo(void *id);
void		ft_usleep(long int time, t_philo *philo);
void		ft_check_death(t_gen *gen);
void		ft_clean_meal(t_gen *gen);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);

long int	get_time(void);


/*************LOCK AND UNLOCK********/

void		ft_unlock_mutex(t_philo *philo);
void		ft_lock_mutex(int id, t_philo *philo);

#endif