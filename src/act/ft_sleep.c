/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:48:25 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:16 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_put_msg("is sleeping", philo);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	if (philo->gen->alive == 1)
	{
		ft_usleep(philo->gen->time_to_sleep, philo);
		ft_put_msg("is thinking", philo);
	}
}
