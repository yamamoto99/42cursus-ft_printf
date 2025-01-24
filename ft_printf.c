/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:33:40 by masayama          #+#    #+#             */
/*   Updated: 2025/01/24 23:45:39 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_fmt(char fmt, va_list *args, int *res)
{
	if (fmt == 'c')
		*res += ft_putchar(va_arg(*args, int));
	else if (fmt == 's')
		*res += ft_putstr(va_arg(*args, char *));
	else if (fmt == 'd' || fmt == 'i')
		*res += ft_putnbr(va_arg(*args, int));
	else if (fmt == 'p')
		*res += ft_putstr("0x") + ft_putbase(va_arg(*args, unsigned long long),
				"0123456789abcdef");
	else if (fmt == 'u')
		*res += ft_putbase(va_arg(*args, unsigned int), "0123456789");
	else if (fmt == 'x')
		*res += ft_putbase(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (fmt == 'X')
		*res += ft_putbase(va_arg(*args, unsigned int), "0123456789ABCDEF");
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

// # include <stdio.h>

// int main(void)
// {
// 	// printf("%c\n", '1');
// 	ft_printf("%s %s\n", "aaa", "bbb");
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int num1 = ft_printf("ft_print : char         >> %c              ", 'a');
// 	printf("<< %d\n", num1);
// 	int num2 = printf("original : char         >> %c              ", 'a');
// 	printf("<< %d\n", num2);
// 	printf("\n");

// 	int num3 = ft_printf("ft_print : string       >> %s          ", "hello");
// 	printf("<< %d\n", num3);
// 	int num4 = printf("original : string       >> %s          ", "hello");
// 	printf("<< %d\n", num4);
// 	printf("\n");

// 	int num5 = ft_printf("ft_print : int          >> %d             ", 42);
// 	printf("<< %d\n", num5);
// 	int num6 = printf("original : int          >> %d             ", 42);
// 	printf("<< %d\n", num6);
// 	printf("\n");

// 	int num7 = ft_printf("ft_print : int          >> %i            ", -42);
// 	printf("<< %d\n", num7);
// 	int num8 = printf("original : int          >> %i            ", -42);
// 	printf("<< %d\n", num8);
// 	printf("\n");

// 	int num9 = 1;
// 	int *p_num9 = &num9;
// 	int num10 = ft_printf("ft_print : pointer      >> %p    ", p_num9);
// 	printf("<< %d\n", num10);
// 	int num11 = printf("original : pointer      >> %p    ", p_num9);
// 	printf("<< %d\n", num11);
// 	printf("\n");

// 	int num12 = ft_printf("ft_print : unsigned int >> %u             ", 42);
// 	printf("<< %d\n", num12);
// 	int num13 = printf("original : unsigned int >> %u             ", 42);
// 	printf("<< %d\n", num13);
// 	printf("\n");

// 	int num14 = ft_printf("ft_print : hex          >> %x       ", -1);
// 	printf("<< %d\n", num14);
// 	int num15 = printf("original : hex          >> %x       ", -1);
// 	printf("<< %d\n", num15);
// 	printf("\n");

// 	int num16 = ft_printf("ft_print : HEX          >> %X             ", 42);
// 	printf("<< %d\n", num16);
// 	int num17 = printf("original : HEX          >> %X             ", 42);
// 	printf("<< %d\n", num17);
// 	printf("\n");

// 	int num18 = ft_printf("ft_print : percent      >> %%              ");
// 	printf("<< %d\n", num18);
// 	int num19 = printf("original : percent      >> %%              ");
// 	printf("<< %d\n", num19);
// 	printf("\n");
// }