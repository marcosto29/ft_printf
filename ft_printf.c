/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:53 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/22 14:28:28 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	size_calculator(char const *input_text, ...)
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

	va_start(arguments, input_text);
	while (*input_text && *input_text != 37)
		write(1, input_text++, 1);
	va_arg(arguments, int);
	return (0);
}

int	main(void)
{
	int	a;

	a = 42;
	ft_printf("hola");
}