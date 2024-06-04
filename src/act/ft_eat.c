/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:49 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 15:57:08 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->gen->alive == 1)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->next_fork);
		ft_put_msg("has taken a fork", philo);
		philo->last_meal = get_time();
		ft_put_msg("is eating", philo);
		philo->ate++;
		ft_usleep(philo->gen->time_to_eat, philo);
	}
}
