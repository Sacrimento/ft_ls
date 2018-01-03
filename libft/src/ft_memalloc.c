/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:33:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:08:55 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_area;
	size_t	i;

	i = 0;
	if (!(new_area = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (new_area == NULL)
		return (NULL);
	while (i < size)
	{
		((char*)new_area)[i] = 0;
		i++;
	}
	return (new_area);
}
