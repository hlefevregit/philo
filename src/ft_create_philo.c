/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:25:30 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 15:04:51 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_tid *philo, void *id)
{
	philo->eat = 0;
	philo->id = (int *)id;
	philo->philo = get_philos(0);
}

void	*ft_create_philo(void *id)
{
	t_tid	philo;
	
	init_philo(&philo, id);
	while (1)
	{
		if (ft_life(&philo) == 0)
			return (0);
	}
}