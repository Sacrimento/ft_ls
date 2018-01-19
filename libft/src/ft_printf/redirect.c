/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:00:12 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:09:10 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*redirect4(t_arg arg, va_list ap)
{
	if (arg.spe == 'x' || arg.spe == 'X')
	{
		if (arg.flag == 0)
			return (ft_umax_itoa_base((unsigned int)va_arg(ap, void *), 16));
		else if (arg.flag == 'l')
			return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 16));
		else if (arg.flag == 'L')
			return (ft_umax_itoa_base((unsigned long long)va_arg(ap, void *),
																		16));
		else if (arg.flag == 'h')
			return (ft_umax_itoa_base((unsigned short)va_arg(ap, void *), 16));
		else if (arg.flag == 'H')
			return (ft_umax_itoa_base((unsigned char)va_arg(ap, void *), 16));
		else if (arg.flag == 'j')
			return (ft_umax_itoa_base((uintmax_t)va_arg(ap, void *), 16));
		else if (arg.flag == 'z')
			return (ft_umax_itoa_base((size_t)va_arg(ap, void *), 16));
	}
	else if (arg.spe == 'D')
		return (ft_max_itoa_base((long)va_arg(ap, void *), 10));
	else
		return (redirect5(arg, ap));
	return (NULL);
}

static char		*redirect3(t_arg arg, va_list ap)
{
	if (arg.spe == 'u')
	{
		if (arg.flag == 0)
			return (ft_umax_itoa_base((unsigned int)va_arg(ap, void *), 10));
		else if (arg.flag == 'l')
			return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 10));
		else if (arg.flag == 'L')
			return (ft_umax_itoa_base((unsigned long long)va_arg(ap, void *),
																		10));
		else if (arg.flag == 'h')
			return (ft_umax_itoa_base((unsigned short)va_arg(ap, void *), 10));
		else if (arg.flag == 'H')
			return (ft_umax_itoa_base((unsigned char)va_arg(ap, void *), 10));
		else if (arg.flag == 'j')
			return (ft_umax_itoa_base((uintmax_t)va_arg(ap, void *), 10));
		else if (arg.flag == 'z')
			return (ft_umax_itoa_base((size_t)va_arg(ap, void *), 10));
	}
	else if (arg.spe == 'U')
		return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 10));
	else
		return (redirect4(arg, ap));
	return (NULL);
}

static char		*redirect2(t_arg arg, va_list ap)
{
	if (arg.spe == 'o')
	{
		if (arg.flag == 0)
			return (ft_umax_itoa_base((unsigned int)va_arg(ap, void *), 8));
		else if (arg.flag == 'l')
			return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 8));
		else if (arg.flag == 'L')
			return (ft_umax_itoa_base((unsigned long long)va_arg(ap, void *),
																			8));
		else if (arg.flag == 'h')
			return (ft_umax_itoa_base((unsigned short)va_arg(ap, void *), 8));
		else if (arg.flag == 'H')
			return (ft_umax_itoa_base((unsigned char)va_arg(ap, void *), 8));
		else if (arg.flag == 'j')
			return (ft_umax_itoa_base((uintmax_t)va_arg(ap, void *), 8));
		else if (arg.flag == 'z')
			return (ft_umax_itoa_base((size_t)va_arg(ap, void *), 8));
	}
	else if (arg.spe == 'O')
		return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 8));
	else if (arg.spe == '%')
		return (singlec('%'));
	else
		return (redirect3(arg, ap));
	return (NULL);
}

char			*redirect(t_arg arg, va_list ap)
{
	char	*s;

	if (arg.spe == 's' && arg.flag != 'a')
		return (!(s = va_arg(ap, char *)) ? null_str() : ft_strdup(s));
	else if (arg.spe == 'p')
		return (ft_max_itoa_base((unsigned long)va_arg(ap, void *), 16));
	else if (arg.spe == 'i' || (arg.spe == 'd' && arg.flag != 'a'))
	{
		if (arg.flag == 'l')
			return (ft_max_itoa_base((long)va_arg(ap, void *), 10));
		else if (arg.flag == 'L')
			return (ft_max_itoa_base((long long)va_arg(ap, void *), 10));
		else if (arg.flag == 0)
			return (ft_max_itoa_base((int)va_arg(ap, void *), 10));
		else if (arg.flag == 'h')
			return (ft_max_itoa_base((short)va_arg(ap, void *), 10));
		else if (arg.flag == 'H')
			return (ft_max_itoa_base((signed char)va_arg(ap, void *), 10));
		else if (arg.flag == 'z')
			return (ft_max_itoa_base((size_t)va_arg(ap, void *), 10));
		return (ft_max_itoa_base((intmax_t)va_arg(ap, void *), 10));
	}
	else
		return (redirect2(arg, ap));
	return (NULL);
}
