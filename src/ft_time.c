/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:35:09 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/27 17:47:47 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *get_philos(t_philo *philo)
{
	static t_philo	*static_philo;

	if (philo != 0)
		static_philo = philo;
	return (static_philo);
}

long int	ft_get_milli(__useconds_t micro)
{
	long int	milli;
	
	milli = micro / 1000;
	return (milli);
}

long int	get_time(void)
{
	struct timeval	time;
	long int		second;
	long int		milli;
	long int		micro;
	
	gettimeofday(&time, NULL);
	second = (time.tv_sec * 1000000);
	micro = (second + time.tv_usec);
	milli = ft_get_milli(micro);
	return (milli);
}