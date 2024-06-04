/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:25:30 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 17:44:32 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_death(t_gen *gen)
{
	int	i;

	i = 0;
	while (i < gen->nbr_philo && gen->all_ate != gen->nbr_meal && gen->alive == 1)
	{
		if (get_time() - gen->philos[i].last_meal > gen->time_to_die)
		{
			gen->alive = 0;
			printf("%ld %d is dead\n", get_time() - gen->start_meal, \
			gen->philos[i].id);
			return ;
		}
		i++;
	}
}

void	ft_clean_meal(t_gen *gen)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&gen->print);
	pthread_mutex_destroy(&gen->print);
	while (i < gen->nbr_philo)
	{
		pthread_mutex_unlock(&gen->philos[i].fork);
		pthread_mutex_destroy(&gen->philos[i].fork);
		pthread_mutex_unlock(gen->philos[i].next_fork);
		pthread_mutex_destroy(gen->philos[i].next_fork);
		pthread_join(gen->philos[i].philo, NULL);
		i++;
	}
}

void	*ft_create_philo(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->gen->nbr_philo == 1)
		ft_put_msg("has taken a fork\n", philo);
	if (philos->id % 2 == 0)
		ft_usleep(philos->gen->time_to_sleep, philo);
	philos->ate = 0;
	while (philos->gen->alive == 1 && \
	philos->ate != philos->gen->nbr_meal)
	{
		ft_eat(philos);
		ft_sleep(philos);
	}
	philos->gen->all_ate++;
	return (NULL);
}