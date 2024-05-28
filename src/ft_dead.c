/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:09:56 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 16:18:27 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead(t_tid *philo)
{
	if (philo->philo->dead == 1)
	{
		ft_unlock_mutex(philo);
		return (1);
	}
	philo->check_eat = (get_time() - philo->philo->start_time);
	if (philo->check_eat - philo->last_eat >= philo->philo->time_to_die)
	{
		ft_put_msg("is dead\n", philo);
		philo->philo->dead = 1;
	}
	if (philo->philo->max_eat == philo->philo->num_philo)
	{
		ft_unlock_mutex(philo);
		return (1);
	}
	return (0);
}
