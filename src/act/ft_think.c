/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:50:37 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/31 14:21:56 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_think(t_tid *philo)
{
	if (ft_dead(philo) == 1)
		return (1);
	ft_put_msg("is thinking\n", philo);
	return (0);
}
