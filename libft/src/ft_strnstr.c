/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:10:49 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:11:57 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!nee[i])
		return ((char*)&(hay[0]));
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == nee[j] && (i + j) < len)
		{
			j++;
			if (!nee[j])
				return ((char*)(&hay[i]));
		}
		i++;
	}
	return (NULL);
}
