/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umax_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:15:47 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 19:49:22 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*zero_value(void)
{
	char	*s;

	s = malloc(2);
	*s = '0';
	*(s + 1) = '\0';
	return (s);
}

static char		*init_base(char *basetype)
{
	char	c;
	int		i;

	c = '0';
	i = 0;
	while (i < 10)
		basetype[i++] = c++;
	c = 'a';
	while (i < 16)
		basetype[i++] = c++;
	return (basetype);
}

static int		count_digit(uintmax_t value, int base)
{
	int		length;

	length = 0;
	while (value != 0)
	{
		value -= value % base;
		value /= base;
		length++;
	}
	return (length);
}

char			*ft_umax_itoa_base(uintmax_t value, int base)
{
	int			length;
	char		*str;
	char		*basetype;
	uintmax_t	temp;

	temp = value;
	basetype = ft_strnew(16);
	basetype = init_base(basetype);
	length = count_digit(value, base);
	str = ft_strnew(count_digit(value, base));
	str[length--] = '\0';
	while (value != 0)
	{
		str[length--] = basetype[value % base];
		value -= value % base;
		value /= base;
	}
	ft_strdel(&basetype);
	temp == 0 ? ft_strdel(&str) : 0;
	return (temp == 0 ? zero_value() : str);
}
