/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:42:14 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/30 20:43:20 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(unsigned long long int n)
{
	int	len;
	int	remain;

	len = 0;
	remain = n % 16;
	if (n / 16)
		len += ft_put_p(n / 16);
	if (remain > 9)
		len += ft_put_c('a' + (remain - 10));
	else
		len += ft_put_d(remain);
	return (len);
}

int	ft_put_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_u(n / 10);
		len += ft_put_u(n % 10);
	}
	else
		len += ft_put_c(n + '0');
	return (len);
}

int	ft_put_x(unsigned int n, char upper)
{
	int	remain;
	int	len;

	len = 0;
	remain = n % 16;
	if (n / 16)
		len += ft_put_x(n / 16, upper);
	if (remain > 9)
	{
		if (upper == 'X')
			len += ft_put_c('A' + (remain - 10));
		else
			len += ft_put_c('a' + (remain - 10));
	}
	else
		len += ft_put_d(remain);
	return (len);
}
