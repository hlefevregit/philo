/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:05:07 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 14:49:51 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_life(t_tid *philo)
{
	philo->time_stamp = (get_time() - philo->philo->start_time);
	if (*philo->id + 1 < philo->philo->num_philo)
	{
		while (philo->philo->mutex[*philo->id].state == 0
			&& philo->philo->mutex[*philo->id + 1].state == 0)
			if (ft_dead(philo) == 1)
				return (0);
	}
	else if (*philo->id != 0)
	{
		while (philo->philo->mutex[*philo->id].state == 0
			&& philo->philo->mutex[0].state == 0)
			if (ft_dead(philo) == 1)
				return (0);
	}
	if (ft_fork(philo) == 1)
		return (0);
	if (ft_eat(philo) == 1)
		return (0);
	if (ft_sleep(philo) == 1)
		return (0);
	if (ft_think(philo) == 1)
		return (0);
	return (1);
}
