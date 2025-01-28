/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:33:40 by masayama          #+#    #+#             */
/*   Updated: 2025/01/29 01:17:24 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pointer(va_list *args)
{
	unsigned long long	ptr;

	ptr = va_arg(*args, unsigned long long);
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putbase(ptr, HEX_LOWER));
}

void	ft_check_fmt(char fmt, va_list *args, int *res)
{
	if (fmt == 'c')
		*res += ft_putchar(va_arg(*args, int));
	else if (fmt == 's')
		*res += ft_putstr(va_arg(*args, char *));
	else if (fmt == 'd' || fmt == 'i')
		*res += ft_putnbr(va_arg(*args, int));
	else if (fmt == 'p')
		*res += handle_pointer(args);
	else if (fmt == 'u')
		*res += ft_putbase(va_arg(*args, unsigned int), DECIMAL);
	else if (fmt == 'x')
		*res += ft_putbase(va_arg(*args, unsigned int), HEX_LOWER);
	else if (fmt == 'X')
		*res += ft_putbase(va_arg(*args, unsigned int), HEX_UPPER);
	else if (fmt == '%')
		*res += ft_putchar('%');
}

int	printf_helper(const char *format, va_list *args)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_fmt(*format, args, &res);
		}
		else
		{
			ft_putchar(*format);
			res++;
		}
		format++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ans;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	ans = printf_helper(format, &args);
	va_end(args);
	return (ans);
}
