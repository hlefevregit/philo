/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:25:30 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:35 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_tid	init_philo(t_tid *philo, void *id)
{
	philo->eat = 0;
	philo->id = (int *)id;
	philo->philo = get_philos(0);
	return (philo);
}

void	*ft_create_philo(void *id)
{
	t_tid	philo;
	
	philo = init_philo(&philo, id);
}