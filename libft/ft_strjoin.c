/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:16:59 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/16 12:21:09 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pt_return;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	pt_return = ft_calloc(sizeof(char), len_s1 + len_s2 + 1);
	if (!pt_return)
		return (0);
	ft_memcpy(pt_return, s1, len_s1);
	ft_memcpy(pt_return + len_s1, s2, len_s2);
	return (pt_return);
}
