/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:07:57 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:28 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_put_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->gen->print);
	if (philo->gen->alive == 1)
	{
		printf("%ld %d %s\n", get_time() - philo->gen->start_meal, \
		philo->id, str);
	}
	pthread_mutex_unlock(&philo->gen->print);
}
