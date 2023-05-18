/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:27:28 by yloutfi           #+#    #+#             */
/*   Updated: 2023/05/18 11:43:33 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str);
	word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int	word_index;

	word_index = 0;
	while (*str == ' ')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ')
			++str;
		while (*str == ' ')
			++str;
	}
}

int	count_words(char *str)
{
	int	num_words;

	num_words = 0;
	while (*str == ' ')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ')
			++str;
		while (*str == ' ')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str, int *ac)
{
	char	**array;

	if (!str)
	{
		*ac = -1;
		return (NULL);
	}
	*ac = count_words(str);
	array = malloc(sizeof(char *) * (*ac + 1));
	array[*ac] = 0;
	fill_words(array, str);
	free(str);
	return (array);
}
