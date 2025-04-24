/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:11:18 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/17 16:33:16 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	int		i;

	if (*little == '\0')
		return ((char *)big);
	len_little = ft_strlen(little);
	i = 0;
	while (*(big + i) && i + len_little <= len)
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
