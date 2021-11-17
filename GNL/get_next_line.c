/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:19:56 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/26 19:20:42 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*output(char *string)
{
	int		i;
	char	*string2;

	i = 0;
	if (string[i] == '\0')
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	string2 = malloc(sizeof(char) * (i + 2));
	if (!string2)
		return (0);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		string2[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		string2[i] = string[i];
		i++;
	}
	string2[i] = '\0';
	return (string2);
}

char	*reminder(char *string)
{
	int		i;
	int		m;
	char	*string2;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free (string);
		return (0);
	}
	string2 = malloc(sizeof(char) * (ft_strlen(string) - i + 1));
	if (!string2)
		return (0);
	m = 0;
	i++;
	while (string[i] != '\0')
		string2[m++] = string[i++];
	string2[m] = '\0';
	free (string);
	return (string2);
}

char	*readline(int fd, char *string)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!search_n(string) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free (buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = readline(fd, str);
	if (!str)
		return (0);
	str2 = output(str);
	str = reminder(str);
	return (str2);
}
