/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:47:53 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:12:06 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	strmodlen(char const *s, char c)
{
	int		max_len;
	int		len;
	int		i;

	len = 0;
	max_len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (len > max_len)
			max_len = len;
		len = 0;
	}
	return (max_len);
}

static int	count_words(const char *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	if (s[0] == c)
	{
		while (s[i] == c)
			i++;
	}
	else
		words = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static char	**fill_tab(char const *s, char **tab, char c)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (j < count_words(s, c))
	{
		z = 0;
		if (!(tab[j] = (char*)malloc(sizeof(char) * (strmodlen(s, c) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
		{
			tab[j][z] = s[i];
			i++;
			z++;
		}
		while (s[i] == c)
			i++;
		tab[j][z] = '\0';
		j++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	if (!(s[0]) || !c)
	{
		tab[0] = 0;
		return (tab);
	}
	tab = fill_tab(s, tab, c);
	tab[count_words(s, c)] = 0;
	return (tab);
}
