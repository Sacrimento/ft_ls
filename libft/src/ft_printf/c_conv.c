/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:03:01 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:08:33 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			encoding_size(unsigned int c)
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

static int			byte_length(int pre, wchar_t *s)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (i < pre)
	{
		size += encoding_size(s[i]);
		i++;
	}
	return (size);
}

static int			wide_pre(t_arg arg, wchar_t *s)
{
	int		total_size;
	int		i;

	i = 0;
	total_size = 0;
	while (s[i])
	{
		if (arg.pre >= 0 && total_size + encoding_size(s[i]) > arg.pre)
			return (i);
		total_size += encoding_size(s[i]);
		i++;
	}
	return (i);
}

void				wide_str(int *len, t_arg arg, wchar_t *s)
{
	int		i;
	char	*width;
	int		pre;
	int		byte_len;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		*len += 6;
		return ;
	}
	pre = wide_pre(arg, s);
	byte_len = byte_length(pre, s);
	if (arg.width > byte_len)
		width = create_width(arg.att.width_modi, arg.width - byte_len);
	(arg.att.width_modi != '-' && arg.width > byte_len) ? ft_putstr(width) : 0;
	while (i < pre)
		*len += ft_putwchar(s[i++]);
	(arg.att.width_modi == '-' && arg.width > byte_len) ? ft_putstr(width) : 0;
	*len += arg.width > byte_len ? ft_strlen(width) : 0;
	arg.width > byte_len ? ft_strdel(&width) : 0;
}

void				c_conv(int *len, t_arg arg, va_list ap)
{
	char	*s;

	if (arg.width != 0)
		s = create_width(arg.att.width_modi, arg.width - 1);
	if (arg.att.width_modi == '-')
	{
		if (arg.spe == 'c' && arg.flag != 'l')
			ft_putchar((char)va_arg(ap, void*));
		else
			*len += ft_putwchar((unsigned int)va_arg(ap, void*));
		arg.width != 0 ? ft_putstr(s) : 0;
	}
	else
	{
		arg.width != 0 ? ft_putstr(s) : 0;
		if (arg.spe == 'c' && arg.flag != 'l')
			ft_putchar((char)va_arg(ap, void*));
		else
			*len += ft_putwchar((unsigned int)va_arg(ap, void*));
	}
	if (arg.spe == 'c' && arg.flag != 'l')
		*len += arg.width != 0 ? ft_strlen(s) + 1 : 1;
	arg.width != 0 ? ft_strdel(&s) : 0;
}
