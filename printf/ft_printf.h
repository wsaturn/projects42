/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:45:54 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/30 20:39:03 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_process(const char *format, va_list ap);
int	ft_put_c(char c);
int	ft_put_d(int n);
int	ft_put_p(unsigned long long int n);
int	ft_put_s(char *s);
int	ft_put_u(unsigned int n);
int	ft_put_x(unsigned int n, char upper);

#endif
