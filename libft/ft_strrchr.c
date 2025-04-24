/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:49 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/17 15:02:11 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*pt_s;

	pt_s = 0;
	while (*s)
	{
		if (*s == (char) c)
			pt_s = (char *)s;
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	return (pt_s);
}
