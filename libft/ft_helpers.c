/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:17 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 14:59:52 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

int	ft_print_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		str++;
		count++;
	}
	return (count);
}

int	ft_print_p(unsigned long long p)
{
	int	count;

	count = 0;
	if (!p)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_putnbr_base_ll(p, "0123456789abcdef");
	return (count);
}

int	ft_print_d(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		n *= -1;
	}
	count += ft_putnbr_base(n, "0123456789");
	return (count);
}
