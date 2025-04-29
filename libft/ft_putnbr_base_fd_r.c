/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:54:18 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/29 12:20:31 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//a base putnbr function that does not accept negatives
//to print negatives, they need a pre parse to make them positives
int	ft_putnbr_base_fd_r(unsigned long long number,
						const char *base, int fd, int base_size)
{
	int		bytes;
	char	changed_number;

	bytes = 0;
	if (number / base_size > 0)
	{
		bytes = ft_putnbr_base_fd_r(number / base_size, base, fd, base_size);
	}
	changed_number = *(base + (number % base_size));
	return (bytes + (int)write(fd, &changed_number, 1));
}
