/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:43 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:09:17 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		reverse_width(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i] == '0')
		i++;
	c = s[i];
	if (c == '-' || c == '+' || c == ' ' || c == 'x' || c == 'X')
	{
		s[i] = s[i - 1];
		if (c == 'x' || c == 'X')
			s[1] = c;
		else
			s[0] = c;
	}
}

void			str_converter(t_arg arg, va_list ap, int *len)
{
	char	*s;

	if (arg.spe == 'c' || arg.spe == 'C')
		c_conv(len, arg, ap);
	else if (arg.spe == 'S' || (arg.spe == 's' && arg.flag == 'l'))
		wide_str(len, arg, (wchar_t *)va_arg(ap, void *));
	else
	{
		s = (arg.spe == 'X') ? ft_strtoupper(redirect(arg, ap)) :
															redirect(arg, ap);
		(*s == '0' && (arg.spe == 'x' || arg.spe == 'X')) ?
														arg.att.diese = 0 : 0;
		s = precision(s, arg);
		reverse_width(s);
		s = flags(s, arg);
		s = width(s, arg);
		arg.width != 0 && arg.att.width_modi == '0' ? reverse_width(s) : 0;
		*len += ft_strlen(s);
		ft_putstr(s);
		ft_strdel(&s);
	}
}
