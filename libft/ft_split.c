/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:13:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 14:41:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;
	int	nb;
	int	is_word;

	i = 0;
	nb = 0;
	len = ft_strlen((char*)s);
	while (i < len && s[i] != '\0')
	{
		is_word = 0;
		while (s[i] != c && i < len)
		{
			is_word = 1;
			i++;
		}
		nb += is_word;
		i++;
	}
	return (nb);
}

static int	word_len(char const *s, char c)
{
	int	word_len;

	word_len = 0;
	while (s[word_len] != c && s[word_len] != '\0')
		word_len += 1;
	return (word_len);
}

char		**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		i;
	int		k;

	if (!(tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	str = (char *)s;
	k = 0;
	while (*str != 0)
	{
		if (*str != c && *str != 0)
		{
			if (!(tab[k] = (char*)malloc(sizeof(char) * word_len(str, c) + 1)))
				return (NULL);
			i = 0;
			while (*str != c && *str != 0)
				tab[k][i++] = *str++;
			tab[k++][i] = 0;
		}
		str += (*str == 0) ? -1 : 0;
		str++;
	}
	tab[k] = NULL;
	return (tab);
}
