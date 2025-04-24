/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:35:47 by matoledo          #+#    #+#             */
/*   Updated: 2025/04/21 21:58:52 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **splitted_word)
{
	char	**pt_aux;

	pt_aux = splitted_word;
	while (*pt_aux)
	{
		free(*pt_aux++);
	}
	free(splitted_word);
}

static unsigned int	ft_splits_number(const char *to_split, char split_character)
{
	unsigned int	splits;

	splits = 1;
	if (ft_strlen(to_split) == 0)
		return (0);
	while (*to_split)
	{
		if (*to_split == split_character)
		{
			while (*to_split == split_character)
			{
				to_split++;
			}
			if (*to_split)
				splits++;
			continue ;
		}
		to_split++;
	}
	return (splits);
}

static unsigned int	ft_letters_counter(const char *to_split, char c)
{
	unsigned int	letters;

	letters = 0;
	while (*to_split && *to_split != c)
	{
		letters++;
		to_split++;
	}
	return (letters);
}

static char	**ft_split_word(char **split, const char *to_split, char c)
{
	char			**pt_splitted;
	char			*splitted;
	unsigned int	letters;

	pt_splitted = split;
	while (*to_split)
	{
		letters = ft_letters_counter(to_split, c);
		splitted = ft_calloc(sizeof(char), letters + 1);
		if (!splitted)
			return (0);
		while (*to_split && *to_split != c)
			*splitted++ = *to_split++;
		*split++ = splitted - letters;
		while (*to_split && *to_split == c)
			to_split++;
	}
	return (pt_splitted);
}

char	**ft_split(char const *s, char c)
{
	char			**pt_return;
	unsigned int	splits;

	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	splits = ft_splits_number(s, c);
	pt_return = ft_calloc(sizeof(char *), splits + 1);
	if (!pt_return)
		return (0);
	if (!ft_split_word(pt_return, s, c))
	{
		free_memory(pt_return);
		return (0);
	}
	return (pt_return);
}
