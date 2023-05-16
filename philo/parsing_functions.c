/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:16 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/16 16:37:25 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(1, "\033[1;31m", ft_strlen("\033[1;31m"));
	write(1, "Error : invalid argument\n", 25);
	write(1, "\033[1;00m", ft_strlen("\033[1;00m"));
	exit(1);
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

void	is_valid_args(char **args, int ac)
{
	if (ac > 4 || ac < 3)
		ft_error();
	if (!check_args(args, ac))
		ft_error();
	if (!check_is_int(args, ac))
		ft_error();
	return ;
}
