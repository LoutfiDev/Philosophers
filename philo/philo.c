/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:39:14 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/18 16:27:13 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data, char **args, int ac, int status)
{
	int	i;

	i = 0;
	while (i < ac)
		free(args[i++]);
	if (args)
		free(args);
	if (data && data->philosophers)
		free(data->philosophers);
	if (data && data->forks)
		free(data->forks);
	if (data && data->philos)
		free(data->philos);
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
		error = pthread_mutex_destroy(&data->forks[i++]);
		if (error == -1)
			return (ft_error("Failed to destroy the mutexes\n"));
	}
	return (0);
}

void	*routine(t_data *data)
{
	(void)data;
	return (NULL);
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
	data = data_init(args, ac);
	if (!data)
		return (ft_free(data, args, ac, 1));
	if (mutexes_init(data) || threads_create(data))
		return (ft_free(data, args, ac, 1));
	// while(routine);
	if (destroy_mutexes(data))
		return (ft_free(data, args, ac, 1));
	ft_free(data, args, ac, 0);
	return (0);
}
