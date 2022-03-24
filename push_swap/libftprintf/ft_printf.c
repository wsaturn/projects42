/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:31:29 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/14 16:31:31 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_sign(char f, va_list as, int j)
{
	char	*str16;

	str16 = "0123456789abcdef";
	if (f == 's')
		return (ft_search(va_arg(as, char *), 0, 2));
	else if (f == 'c')
		return (ft_putchar(j));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr(j));
	else if (f == 'u')
		return (ft_putnbr_base(j, "0123456789", 10, 'u'));
	else if (f == 'x')
		return (ft_putnbr_base(j, str16, 16, 'x'));
	else if (f == 'X')
		return (ft_putnbr_base(j, "0123456789ABCDEF", 16, 'X'));
	else if (f == 'p')
	{
		ft_putstr("0x");
		return (ft_putnbr_base(va_arg(as, size_t), str16, 16, 'p') + 2);
	}
	else
		return (ft_putchar('%'));
}

int	ft_search(char *s, char c, int res)
{
	int	i;

	i = 0;
	if (res == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	else if (res == 1)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (1);
			i++;
		}
		return (0);
	}
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	as;
	char	*str;
	int		i[2];
	int		j;

	i[0] = -1;
	i[1] = 0;
	str = (char *)format;
	va_start(as, format);
	while (str[++i[0]])
	{
		if (str[i[0]] == '%' && ft_search("cspdiuxX%", str[i[0] + 1], 1))
		{
			if (ft_search("cdi", str[i[0] + 1], 1))
				j = va_arg(as, int);
			if (ft_search("uxX", str[i[0] + 1], 1))
				j = va_arg(as, unsigned int);
			i[1] += ft_sign(str[i[0] + 1], as, j);
			i[0]++;
		}
		else
			i[1] += ft_putchar(str[i[0]]);
	}
	va_end(as);
	return (i[1]);
}
