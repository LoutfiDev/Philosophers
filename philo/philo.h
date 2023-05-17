/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:48:08 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/17 16:57:36 by yloutfi          ###   ########.fr       */
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
	int	philo_id;
	int	fork_id;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	eat_times;
}	t_philo;

typedef struct s_data
{
	long long		nbr_philos;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				death;
	int				max_eat_times;
}	t_data;

//parsing function
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
long long	ft_atoi(char *str);
char		**ft_split(char *str, int *ac);
char		*ft_argsjoin(char **args, int nbr);
int			is_valid_args(char **args, int ac);
int			ft_error(char *message);

//initiallize functions
t_philo		*philo_init(char **args);
t_data		*data_init(char **args, int ac);
int			mutexes_init(t_data *data);
int			threads_create(t_data *data);

//philosophers routine
void		*routine(char *data);

#endif