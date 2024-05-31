/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:48:25 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 16:26:59 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_sleep(t_tid *philo)
{
	int	sleep_time;
	
	if (ft_dead(philo) == 1)
		return (1);
	sleep_time = philo->philo->time_to_sleep;
	ft_put_msg("is sleeping\n", philo);
	while (sleep_time > 0)
	{
		usleep(sleep_time / 1000);
		sleep_time--;
		if (ft_dead(philo) == 1)
			return (1);
	}
	philo->time_stamp = get_time() - philo->philo->start_time;
	if (ft_dead(philo) == 1)
		return (1);
	return (0);
}
