/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:22:23 by rluiz             #+#    #+#             */
/*   Updated: 2023/10/18 15:00:35 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft.h"

int	ft_print_c(char c);
int	ft_print_s(char *str);
int	ft_print_p(unsigned long long p);
int	ft_print_d(int n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int n, int upper);
int	ft_parse(const char *format, int *i, va_list args);
int	ft_printf(const char *format, ...);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_base_ll(unsigned long long nbr, char *base);

#endif