/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:13:30 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/03 15:06:32 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc_p(void **p, size_t len)
{
	*p = malloc(len);
	if (*p == NULL)
		return (0);
	return (1);
}

static void	update_save(char **save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buf);
	free(*save);
	*save = tmp;
}

static int	appendline_freesave(char **save, char **line)
{
	int			len;
	char		*tmp;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		tmp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = tmp;
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (READ_EOF);
	}
	return (READ);
}

static int	output(char **save, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *save == NULL)
	{
		if (*save != NULL)
		{
			*line = ft_strdup(*save);
			free(*save);
			*save = NULL;
		}
		else
			*line = ft_strdup("");
		return (READ_EOF);
	}
	else
		return (appendline_freesave(&*save, line));
}

int	get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*save;
	char			buf[BUFF_SIZE + 1];

	ret = 1;
	if (fd < 0)
		return (READ_ERROR);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret >= 0)
			buf[ret] = '\0';
		if (ret <= 0)
			break ;
		if (save == NULL)
			save = ft_strdup(buf);
		else
			update_save(&save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (output(&save, line, ret));
}
