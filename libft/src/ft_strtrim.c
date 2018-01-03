/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:23:53 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:12:21 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_last_char(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i >= 0)
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new_s;
	int		last_char;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	last_char = get_last_char(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	if (s[i] == '\0')
		i = 0;
	if (!(new_s = (char*)malloc(sizeof(char) * (last_char - i + 1))))
		return (NULL);
	while (i < last_char)
	{
		new_s[j] = s[i];
		i++;
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}
