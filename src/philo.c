/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:42:32 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 17:34:40 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(t_philo *philo)
{
	pthread_t	*thr;
	int			i;
	int			*id;

	thr = malloc(sizeof(pthread_t) * (philo->num_philo));
	philo->mutex = malloc(sizeof(t_mutex) * (philo->num_philo));
	id = malloc(sizeof(int) * (philo->num_philo));
	i = 0;
	while (i < philo->num_philo)
	{
		pthread_mutex_init(&philo->mutex[i].mutex, NULL);
		philo->mutex[i].state = 1;
		pthread_mutex_unlock(&philo->mutex[i].mutex);
		id[i] = i;
		i++;
	}
	get_philos(philo);
	i = -1;
	while (++i < philo->num_philo)
	{
		usleep(1000);
		pthread_create(&thr[i], NULL, ft_create_philo, &id[i]);
	}
	i = -1;
	while (++i < philo->num_philo)
		pthread_join(thr[i], NULL);
	i = -1;
	while (++i < philo->num_philo)
		pthread_mutex_destroy(&philo->mutex[i].mutex);
	free(philo->mutex);
	free(id);
	free(thr);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (str_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	init_env(int ac, char **av)
{
	t_philo	philo;
	
	if (check_args(ac, av) == 1)
	{
		philo.num_philo = ft_atoi(av[1]);
		philo.time_to_die = ft_atoi(av[2]);
		philo.time_to_eat = ft_atoi(av[3]);
		philo.time_to_sleep = ft_atoi(av[4]);
		philo.start_time = get_time();
		if (ac != 6)
			philo.max_eat = -1;
		else
			philo.max_eat = ft_atoi(av[5]);
	}
	else
	{
		ft_strerror("Error : Not only digit\n");
		return ;
	}
	ft_philo(&philo);
}

int	main(int ac, char **av)
{
	
	if (ac == 5 || ac == 6)
		init_env(ac, av);
	else
		return (ft_strerror("Error : args error\n"));
	return (0);
}
