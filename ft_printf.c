/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:53 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/24 17:14:11 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (*c++)
	{
		counter++;
	}
	return (counter);
}

void	ft_write_string(char *string, int *bytes)
{
	while (*string)
		*bytes += (int)write(1, string++, 1);
}

int	ft_write_character(char character, int *bytes)
{
	*bytes += (int)write(1, &character, 1);
}

static void	ft_write_base(unsigned long long memory_adress,
						const char *base_chars, int *bytes)
{
	size_t	base;
	char	changed_number;

	base = ft_strlen(base_chars);
	if (memory_adress / base > 0)
	{
		ft_write_base(memory_adress / base, base_chars, bytes);
	}
	changed_number = *(base_chars + (memory_adress % base));
	*bytes += (int)write(1, &changed_number, 1);
}

static void	ft_putnbr(int memory_adress, const char *base_chars, int *bytes)
{
	if (memory_adress < 0)
	{
		memory_adress *= -1;
		*bytes += (int)write(1, "-", 1);
	}
	ft_write_base(memory_adress, base_chars, bytes);
}

static int	ft_print_selector(char type, va_list arguments)
{
	int	bytes;

	bytes = 0;
	if (type == '%')
		bytes = (int)write(1, "%", 1);
	else if (type == 'c')
		ft_write_character((char)va_arg(arguments, int), &bytes);
	else if (type == 's')
		ft_write_string(va_arg(arguments, char*), &bytes);
	else if (type == 'p')
	{
		bytes += (int)write(1, "0x", 2);
		ft_write_base(va_arg(arguments, void *), "0123456789abcdef", &bytes);
	}
	else if (type == 'x')
		ft_write_base(va_arg(arguments, unsigned int), "0123456789abcdef", &bytes);
	else if (type == 'X')
		ft_write_base(va_arg(arguments, unsigned int), "0123456789ABCDEF", &bytes);
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(arguments, int), "0123456789", &bytes);
	else if (type == 'u')
		ft_write_base((unsigned int)va_arg(arguments, int), "0123456789", &bytes);
	return (bytes);
}

int	ft_printf(char const *input_text, ...)
{
	va_list	arguments;
	int	size_return;

	size_return = 0;
	va_start(arguments, input_text);
	while (*input_text)
	{
		if (*input_text == 37)
		{
			size_return += ft_print_selector(*(input_text + 1), arguments);
			input_text += 2;
		}
		else
			size_return += (int)write(1, input_text++, 1);
	}
	va_end(arguments);
	return (size_return);
}
