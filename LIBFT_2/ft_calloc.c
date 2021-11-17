/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:03:17 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/13 15:10:15 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mass;

	mass = malloc(count * size);
	if (mass == NULL)
		return (NULL);
	ft_bzero(mass, count * size);
	return (mass);
}
