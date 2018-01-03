/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:33:21 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:11:35 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	while (s1[i])
		i++;
	while (s2[j] && z < n)
	{
		s1[i + j] = s2[j];
		j++;
		z++;
	}
	s1[i + j] = '\0';
	return (s1);
}
