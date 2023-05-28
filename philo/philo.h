/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:48:08 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/28 15:00:22 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*t_message;
	pthread_mutex_t	*t_eat;
	unsigned long	*timestamp;
	unsigned long	last_meal_time;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat_times;
	int				full_state;
	int				death_state;
}	t_philo;

typedef struct s_data
{
	long long		nbr_philos;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*messages;
	pthread_mutex_t	*eat;
	t_philo			*philos;
	int				death_time;
	unsigned long	*time;
}	t_data;

//parsing function
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, int n);
long long		ft_atoi(char *str);
char			**ft_split(char *str, int *ac);
char			*ft_argsjoin(char **args, int nbr);
int				is_valid_args(char **args, int ac);
int				ft_error(char *message);

//initiallize functions
t_philo			*philo_init(char **args, t_data *data);
t_data			*data_init(char **args);
int				mutexes_init(t_data *data);
int				threads_create(t_data *data);

//philosophers routine
void			*routine(t_philo *data);
void			ft_print(t_philo *philo, char *message);
unsigned long	get_time(void);

#endif