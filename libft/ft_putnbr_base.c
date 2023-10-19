/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:12:58 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 14:59:52 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned int)base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_base_ll(unsigned long long nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
	{
		count += ft_putnbr_base_ll(nbr / base_len, base);
		count += ft_putnbr_base_ll(nbr % base_len, base);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		count++;
	}
	return (count);
}
