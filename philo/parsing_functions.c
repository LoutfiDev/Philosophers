/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/24 14:18:44 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *message)
{
	write(1, "\033[1;31m", ft_strlen("\033[1;31m"));
	while (*message)
		write(1, message++, 1);
	write(1, "\033[1;00m", ft_strlen("\033[1;00m"));
	return (1);
}

unsigned long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->t_message);
	printf("Philosopher %d %s in %ld\n", philo->philo_id, message, get_time() - *philo->timestamp);
	if (!philo->death_state)
		pthread_mutex_unlock(philo->t_message);
}

int	check_args(char **args, int nbr)
{
	int	i;

	if (!args || !(*args))
		return (ft_error("Error: invalid arguments\n"));
	nbr--;
	while (nbr >= 0)
	{
		i = 0;
		while (args[nbr][i])
		{
			if ((args[nbr][i] == '-' || args[nbr][i] == '+') && !i)
				i++;
			if (args[nbr][i] < '0' || args[nbr][i] > '9')
				return (ft_error("Error: invalid arguments\n"));
			i++;
		}
		nbr--;
	}
	return (0);
}

int	check_is_int(char **args, int nbr)
{
	long long	nb;

	nbr--;
	while (nbr >= 0)
	{
		nb = ft_atoi(args[nbr]);
		if (nb <= 0 || nb > 2147483647)
			return (ft_error("Error: arguments must be >0 and <INT_MAX\n"));
		nbr--;
	}
	return (0);
}

int	is_valid_args(char **args, int ac)
{
	int	status;

	status = 0;
	if (ac == -1)
		return (1);
	if (ac > 5 || ac < 4)
		status = ft_error("Error: number of arguments\n");
	if (!status)
		status = check_args(args, ac);
	if (!status)
		status = check_is_int(args, ac);
	return (status);
}
