/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:12:11 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	const char	*ptr;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
				{
					ptr = &(haystack[i]);
					return ((char*)ptr);
				}
			}
		}
		i++;
	}
	return (0);
}
