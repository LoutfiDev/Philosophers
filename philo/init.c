/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:32:54 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/18 16:51:14 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(char **args)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * ft_atoi(args[0]));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < ft_atoi(args[0]))
	{
		philo[i].philo_id = i + 1;
		philo[i].time_to_die = ft_atoi(args[1]);
		philo[i].time_to_eat = ft_atoi(args[2]);
		philo[i].time_to_sleep = ft_atoi(args[3]);
		philo[i].eat_times = 0;
		i++;
	}
	return (philo);
}

t_data	*data_init(char **args, int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nbr_philos = ft_atoi(args[0]);
	data->philosophers = malloc(sizeof(pthread_t) * data->nbr_philos);
	if (!data->philosophers)
		return (NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (!data->forks)
		return (NULL);
	data->philos = philo_init(args);
	if (!data->philos)
		return (NULL);
	data->death = 0;
	if (ac == 5)
		data->max_eat_times = ft_atoi(args[4]);
	else
		data->max_eat_times = -1;
	return (data);
}

int	mutexes_init(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	while (i < data->nbr_philos)
	{
		error = pthread_mutex_init(&data->forks[i], NULL);
		if (error == -1)
			return (ft_error("Failed to initialize the mutexes\n"));
		i++;
	}
	return (0);
}

int	threads_create(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	while (i < data->nbr_philos)
	{
		error = pthread_create(&data->philosophers[i], NULL,
				(void *)routine, (t_data *)data);
		if (error == -1)
			return (ft_error("Error in thread creation.\n"));
		i++;
	}
	return (0);
}
