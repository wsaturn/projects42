/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:09:23 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/02 21:57:10 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*isk;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	isk = (char *)malloc(sizeof(*s) * (len + 1));
	if (!isk)
		return (0);
	while (s[i] != '\0')
	{
		if (i >= start && len > j)
			isk[j++] = s[i];
		i++;
	}
	isk[j] = '\0';
	return (isk);
}
