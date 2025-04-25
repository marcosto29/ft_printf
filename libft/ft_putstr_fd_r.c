/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:40:52 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/25 17:14:58 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_r(char *s, int fd)
{
	int	bytes;

	if (!s)
		return ((int)write(fd, "(null)", 6));
	bytes = (int)ft_strlen(s);
	return ((int)write(fd, s, bytes));
}
