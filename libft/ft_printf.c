/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:40:42 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 14:59:52 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

int	ft_parse(const char *format, int *i, va_list args)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_print_c(va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_print_s(va_arg(args, char *));
	else if (format[*i] == 'p')
		count += ft_print_p(va_arg(args, unsigned long long));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_d(va_arg(args, int));
	else if (format[*i] == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (format[*i] == 'x')
		count += ft_print_x(va_arg(args, unsigned int), 0);
	else if (format[*i] == 'X')
		count += ft_print_x(va_arg(args, unsigned int), 1);
	else if (format[*i] == '%')
		count += ft_print_c('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse(format, &i, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
