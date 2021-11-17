/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:24:00 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/14 12:46:08 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mass1;
	unsigned char	*mass2;

	mass1 = (unsigned char *) s1;
	mass2 = (unsigned char *) s2;
	while (0 < n && *mass1 == *mass2)
	{
		mass1++;
		mass2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*mass1 - *mass2);
}
