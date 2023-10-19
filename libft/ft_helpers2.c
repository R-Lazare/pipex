/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:56:09 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 14:59:52 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(n, "0123456789");
	return (count);
}

int	ft_print_x(unsigned int n, int upper)
{
	int	count;

	count = 0;
	if (upper)
		count += ft_putnbr_base(n, "0123456789ABCDEF");
	else
		count += ft_putnbr_base(n, "0123456789abcdef");
	return (count);
}
