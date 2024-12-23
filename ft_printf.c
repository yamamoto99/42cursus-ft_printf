/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:33:40 by masayama          #+#    #+#             */
/*   Updated: 2024/12/23 22:31:03 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_fmt(char fmt, va_list args, int *res)
{
	if (fmt == 'c')
		*res += ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		*res += ft_putstr(va_arg(args, char *));
	else if (fmt == 'd' || fmt == 'i')
		*res += ft_putnbr(va_arg(args, int));
	// else if (fmt == 'p')
	// else if (fmt == 'u')
	// else if (fmt == 'x')
	// else if (fmt == 'X')
	else if (fmt == '%')
		*res += ft_putchar('%');
}

int	printf_helper(const char *format, va_list args)
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
	ans = printf_helper(format, args);
	va_end(args);
	return (ans);
}

// #include <stdio.h>
// int main(void)
// {
// 	int a = ft_printf("%s\n", "dsd");
// 	printf("%i\n", a);
// 	int b = ft_printf("%c\n", 'c');
// 	printf("%i\n", b);
// 	int c = ft_printf("%i\n", -2147483647);
// 	printf("%i\n", c);
// }