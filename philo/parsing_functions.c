/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/26 11:32:11 by yloutfi          ###   ########.fr       */
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
	// if (!status && ft_atoi(args[0]) == 1)
	// 	status = ft_error("Philosopher 1 died in 0\n");
	return (status);
}
