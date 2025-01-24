/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:38:32 by masayama          #+#    #+#             */
/*   Updated: 2025/01/24 23:41:57 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_putnbr(int nbr);
int		ft_putbase(unsigned long long nbr, char *base);
void	ft_check_fmt(char fmt, va_list *args, int *res);
int		printf_helper(const char *format, va_list *args);
int		ft_printf(const char *format, ...);

#endif
