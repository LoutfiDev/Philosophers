/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:48:34 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/28 15:30:54 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_sleep(unsigned long time)
{
	unsigned long	_time;
	unsigned long	current_time;

	_time = get_time() + time;
	current_time = get_time();
	while (current_time < _time)
	{
		usleep(100);
		current_time = get_time();
	}
}

void	ft_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->t_message);
	printf("Philosopher %d %s in %ld\n", philo->philo_id, message,
		get_time() - *philo->timestamp);
	pthread_mutex_unlock(philo->t_message);
}

int	ft_eat(t_philo *philo, int *eat)
{
	int	state;

	state = 0;
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken his right fork");
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken his left fork");
	ft_print(philo, "is eating");
	pthread_mutex_lock(philo->t_eat);
	philo->last_meal_time = get_time();
	*eat += 1;
	if (*eat == philo->max_eat_times)
	{
		philo->full_state = 1;
		state = 1;
	}
	ft_sleep((unsigned long)(philo->time_to_eat));
	pthread_mutex_unlock(philo->t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (state);
}

void	*routine(t_philo *philo)
{
	int	eat;

	eat = 0;
	while (1)
	{
		if (ft_eat(philo, &eat))
			return (NULL);
		ft_print(philo, "is sleeping");
		ft_sleep((unsigned long)(philo->time_to_sleep));
		ft_print(philo, "is thinking");
	}
}
