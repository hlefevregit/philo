/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:18:17 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/28 15:26:30 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			ft_putchar(nb + '0');
		}
	}
}


void	ft_putnbr_long(long int nb)
{

	if (nb >= 10)
	{
		ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
