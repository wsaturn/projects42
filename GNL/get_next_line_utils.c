/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:35:05 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/25 14:40:30 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*mass;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mass = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!mass)
		return (0);
	y = 0;
	x = 0;
	while (s1[y])
		mass[x++] = s1[y++];
	y = 0;
	while (s2[y])
		mass[x++] = s2[y++];
	mass[x] = '\0';
	free(s1);
	return (mass);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*search_n(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (!s[i])
			return (0);
		++i;
	}
	return ((char *)&s[i]);
}
