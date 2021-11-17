/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:17:44 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/18 21:10:22 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_poisk(char element, char const *massiv)
{
	int	i;

	i = 0;
	while (massiv[i] != '\0')
	{
		if (massiv[i] == element)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	size_t	k;
	size_t	i;
	char	*res;

	if (!s1 || !set)
		return (0);
	n = 0;
	while (s1[n] != '\0' && ft_poisk(s1[n], set))
		n++;
	k = ft_strlen(s1);
	while (k > n && ft_poisk(s1[k - 1], set))
		k--;
	res = (char *)malloc(sizeof(*s1) * (k - n + 1));
	if (!res)
		return (0);
	i = 0;
	while (k > n)
	{
		res[i] = s1[n];
		n++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
