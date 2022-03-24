/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:14:38 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/04 16:09:02 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 24 || key == 27 || key == 28 || \
	key == 126 || key == 125 || key == 123 || key == 124 || \
	key == 23 || key == 21 || key == 19 || key == 22);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24)
		matrix[0][0].scale += 3;
	if (key == 27)
		matrix[0][0].scale -= 3;
	if (key == 28)
		matrix[0][0].z_scale += 1;
	if (key == 19)
		matrix[0][0].z_scale -= 1;
	if (key == 126)
		matrix[0][0].shift_y -= 10;
	if (key == 125)
		matrix[0][0].shift_y += 10;
	if (key == 123)
		matrix[0][0].shift_x -= 10;
	if (key == 124)
		matrix[0][0].shift_x += 10;
	if (key == 23)
		matrix[0][0].is_isometric = 0;
	if (key == 21)
		matrix[0][0].angle += 0.05;
	if (key == 22)
		matrix[0][0].angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		do_key(key, matrix);
		draw(matrix);
	}
	if (key == '5')
	{
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
