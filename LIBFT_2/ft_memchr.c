/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:47:23 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/18 15:00:00 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*mass;

	i = 0;
	mass = (char *) s;
	while (i < n)
	{
		if (mass[i] == (char)c)
			return (&mass[i]);
		i++;
	}
	return (NULL);
}
