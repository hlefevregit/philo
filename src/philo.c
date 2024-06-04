/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:42:32 by hulefevr          #+#    #+#             */
/*   Updated: 2024/06/04 17:47:12 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_gen *gen)
{
	int	i;

	i = 0;
	gen->philos = malloc(sizeof(t_philo) * gen->nbr_philo);
	if (!gen->philos)
		return (1);
	while (i < gen->nbr_philo)
	{
		gen->philos[i].id = i + 1;
		if (pthread_mutex_init(&gen->philos[i].fork, NULL))
		{
			free(gen->philos);
			gen->philos = NULL;
			return (2);
		}
		if (i == gen->nbr_philo - 1)
			gen->philos[i].next_fork = &gen->philos[0].fork;
		else
			gen->philos[i].next_fork = &gen->philos[i + 1].fork;
		gen->philos[i].gen = gen;
		i++;
	}
	gen->all_ate = 0;
	if (pthread_mutex_init(&gen->print, NULL))
		return (3);
	return (0);
}

int	ft_philo(t_gen *gen)
{
	int	i;

	i = 0;
	gen->alive = 1;
	gen->start_meal = get_time();
	if (!init_philo(gen))
	{
		while (i < gen->nbr_philo && gen->alive == 1)
		{
			if (get_time() - gen->start_meal > gen->time_to_die)
			{
				gen->alive = 0;
				usleep(1000);
				printf("%ld %d", get_time() - gen->start_meal, i + 1);
				gen->nbr_philo = i + 1;
				return (1);
			}
			gen->philos[i].last_meal = gen->start_meal;
			pthread_create(&gen->philos[i].philo, NULL, ft_create_philo, &gen->philos[i]);
			usleep(100);
			i++;
		}
		return (0);
	}
	return (1);
}


int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (str_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_gen	init_env(int ac, char **av, t_gen philo)
{
	if (check_args(ac, av) == 1)
	{
		philo.nbr_philo = ft_atoi(av[1]);
		philo.time_to_die = ft_atoi(av[2]);
		philo.time_to_eat = ft_atoi(av[3]);
		philo.time_to_sleep = ft_atoi(av[4]);
		philo.start_meal = get_time();
		if (ac != 6)
			philo.nbr_meal = -1;
		else
			philo.nbr_meal = ft_atoi(av[5]);
		return (philo);
	}
	philo.nbr_philo = -1;
	return (philo);
	
}

int	main(int ac, char **av)
{
	t_gen	gen;

	if (ac == 5 || ac == 6)
	{
		gen = init_env(ac, av, gen);
		if (gen.nbr_philo == -1)
			return(ft_strerror("Error : Not only digit\n"));
		if (ft_philo(&gen))
			return (ft_strerror("Error : during creation\n"));
		while (gen.alive == 1 && gen.all_ate != gen.nbr_philo)
			ft_check_death(&gen);
		ft_clean_meal(&gen);
		free(gen.philos);
		gen.philos = NULL;
		return (0);
	}
	return (ft_strerror("Error : args error\n"));
}
