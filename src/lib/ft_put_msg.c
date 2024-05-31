/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:07:57 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 15:53:10 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_put_msg(char *str, t_tid *philo)
{
	printf("%ld %i %s", (get_time() - philo->philo->start_time)
		, *philo->id, str);
}
