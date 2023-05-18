/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:04:42 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/18 11:46:18 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{	
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	null_args(char **args, int nbr)
{
	int	i;

	i = 0;
	if (nbr == 1)
		return (ft_error("Error: invalid arguments\n"));
	while (i < nbr)
	{
		if (!args[i] || !args[i][0] || args[i][0] == ' ')
			return (ft_error("Error: invalid arguments\n"));
		i++;
	}
	return (0);
}

char	*ft_argsjoin(char **args, int nbr)
{
	int		i;
	int		j;
	char	*res;

	if (null_args(args, nbr))
		return (0);
	i = 1;
	j = 0;
	while (i < nbr)
		j += ft_strlen(args[i++]);
	res = malloc((j + nbr) * sizeof(char));
	if (res == NULL)
		return (0);
	i = 1;
	j = 0;
	while (i < nbr)
	{
		while ((*args[i]))
			res[j++] = (*args[i]++);
		if (i < nbr - 1)
			res[j++] = ' ';
		i++;
	}
	res[j] = '\0';
	return (res);
}