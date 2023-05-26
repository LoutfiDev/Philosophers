/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:32:54 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/26 15:52:32 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(char **args, t_data *data)
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
		philo[i].right_fork = &data->forks[i];
		philo[i].left_fork = &data->forks[(i + 1) % data->nbr_philos];
		philo[i].t_message = data->messages;
		philo[i].time_to_eat = ft_atoi(args[2]);
		philo[i].time_to_sleep = ft_atoi(args[3]);
		philo[i].max_eat_times = -1;
		if (args[4])
			philo[i].max_eat_times = ft_atoi(args[4]);
		philo[i].last_meal_time = get_time();
		philo[i].full_state = 0;
		philo[i].death_state = 0;
		philo[i++].timestamp = data->time;
	}
	return (philo);
}

t_data	*data_init(char **args)
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
	data->messages = malloc(sizeof(pthread_mutex_t));
	if (!data->messages)
		return (NULL);
	data->time = malloc(sizeof(unsigned long));
	if (!data->time)
		return (NULL);
	*data->time = get_time();
	data->philos = philo_init(args, data);
	if (!data->philos)
		return (NULL);
	data->death_time = ft_atoi(args[1]);
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
	error = pthread_mutex_init(data->messages, NULL);
	if (error == -1)
		return (ft_error("Failed to initialize the mutexes\n"));
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
				(void *)routine, (t_philo *)&data->philos[i]);
		if (error == -1)
			return (ft_error("Error in thread creation.\n"));
		i++;
		pthread_detach(data->philosophers[i]);
		usleep(100);
	}
	return (0);
}
