/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:44:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/17 15:03:48 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*pt_char;

	pt_char = s;
	while (n--)
	{
		if (*pt_char == (char) c)
		{
			return ((char *)pt_char);
		}
		pt_char++;
	}
	return (0);
}
