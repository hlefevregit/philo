/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:37:06 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 16:51:21 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_fork(t_tid *philo)
{
	ft_lock_mutex(1, philo);
	philo->time_stamp = get_time() - philo->philo->start_time;
	if (ft_dead(philo) == 1)
		return (1);
	ft_put_msg("is eating\n", philo);
	if (*philo->id + 1 < philo->philo->num_philo)
	{
		while (philo->philo->mutex[*philo->id].state == 0
			&& philo->philo->mutex[*philo->id + 1].state == 0)
			if (ft_dead(philo) == 1)
				return (1);
		ft_lock_mutex(2, philo);
	}
	else
	{
		while (philo->philo->mutex[*philo->id].state == 0
			&& philo->philo->mutex[0].state == 0)
			if (ft_dead(philo) == 1)
				return (0);
		ft_lock_mutex(0, philo);
	}
	philo->time_stamp = get_time() - philo->philo->start_time;
	if (ft_dead(philo) == 1)
		return (1);
	ft_put_msg("has taken a fork\n", philo);
	return (0);
}
