/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:38:32 by masayama          #+#    #+#             */
/*   Updated: 2025/01/28 23:50:03 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_putnbr(int nbr);
int		ft_putbase(unsigned long long nbr, char *base);
void	ft_check_fmt(char fmt, va_list *args, int *res);
int		printf_helper(const char *format, va_list *args);
int		ft_printf(const char *format, ...);

#endif
