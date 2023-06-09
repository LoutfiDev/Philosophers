/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:39:14 by yloutfi           #+#    #+#             */
/*   Updated: 2023/06/02 16:03:00 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data, char **args, int ac, int status)
{
	while (ac > 0)
		free(args[--ac]);
	if (args)
		free(args);
	if (data && data->philosophers)
		free(data->philosophers);
	if (data && data->forks)
		free(data->forks);
	if (data && data->messages)
		free(data->messages);
	if (data && data->death)
		free(data->death);
	if (data && data->full)
		free(data->full);
	if (data && data->philos)
		free(data->philos);
	if (data && data->time)
		free(data->time);
	if (data)
		free(data);
	if (status)
		return (1);
	return (0);
}

int	destroy_mutexes(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < data->nbr_philos)
	{
		error = pthread_mutex_destroy(&data->forks[i]);
		if (error == -1)
			return (ft_error("Failed to destroy the mutexes\n"));
		error = pthread_mutex_destroy(&data->death[i]);
		if (error == -1)
			return (ft_error("Failed to destroy the mutexes\n"));
		error = pthread_mutex_destroy(&data->full[i]);
		if (error == -1)
			return (ft_error("Failed to destroy the mutexes\n"));
		i++;
	}
	error = pthread_mutex_destroy(data->messages);
	if (error == -1)
		return (ft_error("Failed to destroy the mutexes\n"));
	return (0);
}

int	check_death(t_data *data)
{
	int				i;
	unsigned long	last_time;
	unsigned long	full_state;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(data->philos[i].t_death);
		last_time = data->philos[i].last_meal_time;
		pthread_mutex_unlock(data->philos[i].t_death);
		pthread_mutex_lock(data->philos[i].t_full);
		full_state = data->philos[i].full_state;
		pthread_mutex_unlock(data->philos[i].t_full);
		if (get_time() > last_time + (unsigned long)data->death_time
			&& !full_state)
		{
			pthread_mutex_lock(data->philos[i].t_message);
			printf("Philosopher %d %s in %ld\n", data->philos[i].philo_id,
				"died", get_time() - *data->philos[i].timestamp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_full(t_data *data)
{
	int	i;
	int	j;
	int	full_state;

	i = 0;
	j = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(data->philos[i].t_full);
		full_state = data->philos[i].full_state;
		pthread_mutex_unlock(data->philos[i].t_full);
		if (full_state)
			j++;
		i++;
	}
	if (j == i - 1 && i > 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	**args;
	char	*str;

	str = ft_argsjoin(av, ac);
	args = ft_split(str, &ac);
	if (is_valid_args(args, ac))
		return (ft_free(NULL, args, ac, 1));
	data = data_init(args);
	if (!data)
		return (ft_free(data, args, ac, 1));
	if (mutexes_init(data) || threads_create(data))
		return (ft_free(data, args, ac, 1));
	while (1)
		if (check_full(data) || check_death(data))
			break ;
	ft_stop(data);
	ft_sleep(100);
	if (destroy_mutexes(data))
		return (ft_free(data, args, ac, 1));
	ft_free(data, args, ac, 0);
	return (0);
}
