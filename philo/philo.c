/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:39:14 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/18 12:17:08 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data, char **args, int ac)
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
	return (1);
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
		return (ft_free(NULL, args, ac));
	data = data_init(args, ac);
	if (!data)
		return (ft_free(data, args, ac));
	if (mutexes_init(data) || threads_create(data))
		return (ft_free(data, args, ac));
	// while(1);
	return (0);
}
