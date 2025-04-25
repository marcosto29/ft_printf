/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:53 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/25 18:44:27 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	ft_parse_num(long long number, const char *base_char, int fd)
{
	int	bytes_number;

	bytes_number = 0;
	if (number < 0)
	{
		number *= -1;
		bytes_number += (int)write(1, "-", 1);
	}
	bytes_number += ft_putnbr_base_fd_r(number, base_char, fd);
	return (bytes_number);
}

int	ft_parse_mem(unsigned long long number, const char *base_chars, int fd)
{
	if (!number)
		return ((int)write(fd, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr_base_fd_r(number, base_chars, 1) + 2);
}

static int	ft_print_selector(char type, va_list args)
{
	if (type == '%')
		return (ft_putchar_fd_r('%', 1));
	else if (type == 'c')
		return (ft_putchar_fd_r((char)va_arg(args, int), 1));
	else if (type == 's')
		return (ft_putstr_fd_r(va_arg(args, char *), 1));
	else if (type == 'p')
		return (ft_parse_mem((unsigned long long)va_arg(args, void *),
				"0123456789abcdef", 1));
	else if (type == 'x')
		return (ft_putnbr_base_fd_r(va_arg(args, unsigned int),
				"0123456789abcdef", 1));
	else if (type == 'X')
		return (ft_putnbr_base_fd_r(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1));
	else if (type == 'd' || type == 'i')
		return (ft_parse_num(va_arg(args, int),
				"0123456789", 1));
	else if (type == 'u')
		return (ft_putnbr_base_fd_r((unsigned int)va_arg(args, int),
				"0123456789", 1));
	return (0);
}

int	ft_printf(char const *input_text, ...)
{
	va_list	args;
	int		size_return;

	size_return = 0;
	va_start(args, input_text);
	while (*input_text)
	{
		if (*input_text == 37)
		{
			size_return += ft_print_selector(*(input_text + 1), args);
			input_text += 2;
		}
		else
			size_return += (int)write(1, input_text++, 1);
	}
	va_end(args);
	return (size_return);
}
