/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:48:08 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/16 16:54:38 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	nbr_philos;
	philos;
	forks;
	death;
	nbr_eat_times
}	t_data;

typedef struct s_philo
{
	int	philo_id;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int	eated_times;
}	t_philo;

//parsing function
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
long long	ft_atoi(char *str);
char		**ft_split(char *str, int *ac);
char		*ft_argsjoin(char **args, int nbr);
void		is_valid_args(char **args, int ac);
#endif