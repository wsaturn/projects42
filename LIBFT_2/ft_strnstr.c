/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:40:42 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/19 14:39:41 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find(const char *haystack, const char *needle, size_t len)
{
	while (*haystack && *needle && (*haystack == *needle) && len)
	{
		++haystack;
		++needle;
		--len;
	}
	if (!*needle)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ft_find(haystack, needle, len))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
