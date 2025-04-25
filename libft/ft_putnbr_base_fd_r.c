/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:54:18 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/25 17:59:07 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd_r(unsigned long long number,
						const char *base_chars, int fd)
{
	int		bytes_number;
	int		base;
	char	changed_number;

	bytes_number = 0;
	base = (int)ft_strlen(base_chars);
	if (number / base > 0)
	{
		bytes_number = ft_putnbr_base_fd_r(number / base, base_chars, fd);
	}
	changed_number = *(base_chars + (number % base));
	return (bytes_number + (int)write(fd, &changed_number, 1));
}
