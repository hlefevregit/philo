/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:07:57 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 16:18:02 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_put_msg(char *str, t_tid *philo)
{
	philo->time_stamp = (get_time() - philo->philo->start_time);
	ft_putnbr_long(philo->time_stamp);
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putchar(' ');
	ft_putstr(str);	
}