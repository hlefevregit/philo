/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:11:49 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 15:16:24 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlock_mutex(t_tid *philo)
{
	pthread_mutex_unlock(&philo->philo->mutex[*philo->id].mutex);
	philo->philo->mutex[*philo->id].state = 1;
	if (*philo->id + 1 < philo->philo->num_philo)
	{
		pthread_mutex_unlock(&philo->philo->mutex[*philo->id + 1].mutex);
		philo->philo->mutex[*philo->id + 1].state = 1;
	}
	else
	{
		pthread_mutex_unlock(&philo->philo->mutex[0].mutex);
		philo->philo->mutex[0].state = 1;
	}
}