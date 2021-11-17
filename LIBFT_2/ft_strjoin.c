/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:40:24 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/20 18:56:15 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*summ;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	summ = (char *)malloc(sizeof(*summ) * (1 + (ft_strlen
					(s1) + (ft_strlen(s2)))));
	if (summ == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		summ[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		summ[i] = *s2;
		s2++;
		i++;
	}
	summ[i] = '\0';
	return (summ);
}
