/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:17:02 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/04 13:22:38 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("file does not exist");
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_dots_from_line(line, matrix_of_dots, y++);
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
