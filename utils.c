/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:04:18 by masayama          #+#    #+#             */
/*   Updated: 2025/01/28 23:49:56 by masayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_putbase(unsigned long long nbr, char *base)
{
	int					i;
	unsigned long long	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		i += ft_putbase(nbr / base_len, base);
	return (i + ft_putchar(base[nbr % base_len]));
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		i++;
	}
	return (i + ft_putbase(nbr, DECIMAL));
}
