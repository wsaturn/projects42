/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:12:52 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/04 13:23:05 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	sub_len(const char *start, char c)
{
	int	i;

	i = 0;
	while (start[i] != c && start[i])
		i++;
	return (i);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = ft_substr(&str[i], 0, sub_len(&str[i], c));
			if (NULL == res[j++])
				return (free_arr(res));
			i += sub_len(&str[i], c);
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
