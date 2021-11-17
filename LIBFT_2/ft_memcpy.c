/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:20:05 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/14 12:19:21 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*ds;

	i = 0;
	if (!dst && !src)
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
