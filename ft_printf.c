/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:53 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/23 18:29:48 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	ft_write_string(va_list arguments)
{
	char	*string;

	string = va_arg(arguments, char*);
	while (*string)
		write(1, string++, 1);
}

void	ft_write_character(va_list arguments)
{
	char	character;

	character = (char)va_arg(arguments, int);
	write(1, &character, 1);
}

char	*ft_decimal_to_hexadecimal(int decimal, char *hexadecimal)
{
	char	hex_base[] = "0123456789ABCDEF";
	char	*pt_base = hex_base;
	//make this with hex_base = ft_strdup("0123456789ABCDEF");
	if (decimal / 16 > 0)
	{
		hexadecimal = ft_decimal_to_hexadecimal(decimal / 16, hexadecimal);
	}
	*hexadecimal = *(pt_base + (decimal % 16));
	return (hexadecimal + 1);
}

void	ft_write_memory(va_list arguments)
{
	int		memory_adress;
	int		aux;
	int		size;
	char	*hexa_memory;

	memory_adress = va_arg(arguments, void *);
	if (memory_adress < 0)
	{
		memory_adress *= -1;
	}
	size = 0;
	aux = memory_adress;
	while (aux > 0)
	{
		size++;
		aux /= 16;
	}
	//make this with ft_calloc
	hexa_memory = malloc(sizeof (char) * size + 1);
	ft_decimal_to_hexadecimal(memory_adress, hexa_memory);
	write(1, "0x", 2);
	while (*hexa_memory)
		write(1, hexa_memory++, 1);
}

static void	ft_print_selector(char type, va_list arguments)
{

	//spdiuxX %
	if (type == 'c')
		ft_write_character(arguments);
	if (type == 's')
		ft_write_string(arguments);
	if (type == 'p')
		ft_write_memory(arguments);
	// if (type == 'd')
	// if (type == 'i')
	// if (type == 'u')
	// if (type == 'x')
	// if (type == 'X')
	// if (type == 37)
}
static int	size_calculator(char const *input_text, ...)
{
	int	size;

	//size = ft_strlen(input_text);
	return (size);
}
//the return value is the number of bytes printed
int	ft_printf(char const *input_text, ...)
{
	va_list	arguments;
	int	size_return;
	void *variable;

	va_start(arguments, input_text);
	while (*input_text)
	{
		if (*input_text == 37)
			ft_print_selector(*(input_text + 1), arguments);
		write(1, input_text++, 1);
	}

	va_arg(arguments, int);
	return (0);
}

int	main(void)
{
	int	b;

	b = 1224235235;
	ft_printf("hola %p", &b);
}