/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:53 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/23 13:45:53 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_selector(char type, va_list )
{

	//cspdiuxX %
	if (type == "c")
		write(1, 1);
	if (type == "s")
	if (type == "p")
	if (type == "d")
	if (type == "i")
	if (type == "u")
	if (type == "x")
	if (type == "X")
	if (type == 37)
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
		{

			print_selector(*input_text++);
		}
		write(1, input_text++, 1);
	}

	va_arg(arguments, int);
	return (0);
}

int	main(void)
{
	int	a;

	a = 42;
	ft_printf("hola %c", 3);
}