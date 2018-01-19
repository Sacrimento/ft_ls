/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:47:54 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/15 14:52:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				get_encoding_size(wint_t c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x1fffff)
		return (4);
	else if (c <= 0x3ffffff)
		return (5);
	else if (c <= 0x7fffffff)
		return (6);
	else
		return (-1);
}

unsigned char	get_mask(int size)
{
	if (size == 2)
		return (0xC0);
	else if (size == 3)
		return (0xE0);
	else if (size == 4)
		return (0xF0);
	else if (size == 5)
		return (0xF8);
	else if (size == 6)
		return (0xFC);
	return (0);
}

int				ft_putwchar(wint_t c)
{
	int				size;
	unsigned char	byte;
	unsigned char	mask;

	if ((size = get_encoding_size(c)) == 1)
		return (write(1, &c, 1));
	else if (size == -1)
		return (-1);
	mask = get_mask(size);
	byte = (c >> (6 * --size)) | mask;
	write(1, &byte, 1);
	while (size-- > 0)
	{
		byte = ((c >> (6 * size)) & 63) | 128;
		write(1, &byte, 1);
	}
	return (get_encoding_size(c));
}
