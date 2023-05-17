/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/17 14:27:07 by yloutfi          ###   ########.fr       */
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
		return (0);
	while (nbr >= 0)
	{
		i = 0;
		while (args[nbr][i])
		{
			if (args[nbr][i] == '+' && !i)
				i++;
			if (args[nbr][i] < '0' || args[nbr][i] > '9')
				return (0);
			i++;
		}
		nbr--;
	}
	return (1);
}

int	check_is_int(char **args, int nbr)
{
	long long	nb;

	while (nbr >= 0)
	{
		nb = ft_atoi(args[nbr]);
		if (nb <= 0 || nb > 2147483647)
			return (0);
		nbr--;
	}
	return (1);
}

int	is_valid_args(char **args, int ac)
{
	int	status;

	status = 0;
	if (ac > 4 || ac < 3)
		status = ft_error("Error: number of arguments\n");
	if (!check_args(args, ac) && !status)
		status = ft_error("Error: invalid arguments\n");
	if (!check_is_int(args, ac) && !status)
		status = ft_error("Error: arguments must be >0 and <INT_MAX\n");
	return (status);
}
