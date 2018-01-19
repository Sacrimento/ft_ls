/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:20:10 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:08:58 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		str_controller(char *str, va_list ap)
{
	int		i;
	int		count;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		count = 1;
		if (str[i] == '%')
		{
			while (!v_spe(str[i + count]) && str[i + count])
				count++;
			is_format_v(get_struct(ft_strsub(str, ++i, count), ap), ap, &len)
															? i += count : 0;
		}
		else if (str[i] == '<')
			i += colorise(&(str[i]));
		if (str[i] && str[i] != '%' && str[i] != '<' && (++len))
			ft_putchar(str[i++]);
	}
	ft_strdel(&str);
	return (len);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	len = str_controller(ft_strdup((char*)fmt), ap);
	va_end(ap);
	return (len);
}
