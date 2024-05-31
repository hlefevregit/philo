/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:49 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 17:37:33 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(t_tid *philo)
{
	int	eat_time;

	eat_time = philo->philo->time_to_eat;
	philo->time_stamp = (get_time() - philo->philo->start_time);
	if (ft_dead(philo) == 1)
	{
		ft_unlock_mutex(philo);
		return (1);
	}
	ft_put_msg("is eating\n", philo);
	philo->eat++;
	if (philo->eat == philo->philo->max_eat)
		philo->philo->eaten++;
	if (philo->philo->eaten == philo->philo->num_philo || ft_dead(philo) == 1)
		return (1);
	philo->last_eat = get_time() - philo->philo->start_time;
	while (eat_time > 0)
	{
		usleep(1000);
		eat_time--;
		if (ft_dead(philo) == 1)
		{
			ft_unlock_mutex(philo);
			return (1);
		}
	}
	ft_unlock_mutex(philo);
	philo->time_stamp = get_time() - philo->philo->start_time;
	if (ft_dead(philo) == 1)
	{
		ft_unlock_mutex(philo);
		return (1);
	}
	return (0);
}