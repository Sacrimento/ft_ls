/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:32:41 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:09:21 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		overlap(void *dst, const void *src, size_t len)
{
	while (len--)
	{
		if (src == dst)
			return (1);
		src++;
	}
	return (0);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (overlap(dst, src, len))
	{
		dst = dst + len;
		src = src + len;
		while (len--)
		{
			src--;
			dst--;
			*(unsigned char*)dst = *(unsigned char*)src;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
