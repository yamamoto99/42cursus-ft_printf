/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masayama <masayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:04:18 by masayama          #+#    #+#             */
/*   Updated: 2024/11/30 15:50:17 by masayama         ###   ########.fr       */
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
	while (str[i] != 0)
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return 11;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		i++;
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
	}
	return (i + ft_putchar(nbr % 10 + '0'));
}
