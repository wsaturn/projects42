/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:24:42 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/30 20:39:01 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (*format == '%')
		len = len + ft_put_c('%');
	else if (*format == 'c')
		len = len + ft_put_c(va_arg(ap, int));
	else if (*format == 'u')
		len = len + ft_put_u(va_arg(ap, unsigned int));
	else if (*format == 's')
		len = len + ft_put_s(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		len = len + ft_put_d(va_arg(ap, int));
	else if (*format == 'x')
		len = len + ft_put_x(va_arg(ap, unsigned int), 'x');
	else if (*format == 'X')
		len = len + ft_put_x(va_arg(ap, unsigned int), 'X');
	else if (*format == 'p')
	{
		len = len + ft_put_s("0x");
		len = len + ft_put_p(va_arg(ap, unsigned long long int));
	}
	return (len);
}
