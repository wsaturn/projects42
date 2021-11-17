/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:56:35 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/15 22:27:21 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mass;

	i = 0;
	if (!s || !f)
		return (NULL);
	mass = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!mass)
		return (NULL);
	while (s[i] != '\0')
	{
		mass[i] = f(i, s[i]);
		i++;
	}
	mass[i] = '\0';
	return (mass);
}
