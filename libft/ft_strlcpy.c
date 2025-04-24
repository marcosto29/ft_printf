/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:00:41 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/16 17:35:49 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;
	char	*pt_dest;

	counter = ft_strlen(src);
	if (size == 0)
		return (counter);
	pt_dest = dest;
	while (size-- > 1 && *src)
		*pt_dest++ = *src++;
	*pt_dest = '\0';
	return (counter);
}
