/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:14:57 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/04 15:45:12 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	modul(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

float	maksimalnoe(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = maksimalnoe(modul(step_x), modul(step_y));
	step_x /= max;
	step_y /= max;
	if (b.z || a.z)
		color = 0x92B30F;
	else
		color = 0xBBFAFF;
	if (b.z != a.z)
		color = 0x87A50D;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
