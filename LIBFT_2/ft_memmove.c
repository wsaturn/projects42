/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:02:33 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/14 15:36:28 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ds;
	const unsigned char	*sr;

	i = 0;
	ds = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (ds < sr)
	{
		while (i < len)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			ds[i - 1] = sr[i - 1];
			i--;
		}
	}
	return (dst);
}
