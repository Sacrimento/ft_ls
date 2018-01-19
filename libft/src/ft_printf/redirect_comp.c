/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_comp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:21:58 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:09:06 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*singlec(int c)
{
	char	*str;

	str = ft_strnew(1);
	*str = c;
	*(str + 1) = '\0';
	return (str);
}

char			*null_str(void)
{
	char	*s;

	s = ft_strnew(6);
	*(s) = '(';
	*(s + 1) = 'n';
	*(s + 2) = 'u';
	*(s + 3) = 'l';
	*(s + 4) = 'l';
	*(s + 5) = ')';
	*(s + 6) = '\0';
	return (s);
}

void			print_array(t_arg arg, va_list ap)
{
	int		i;
	char	**sarray;
	int		*darray;

	i = 0;
	if (arg.spe == 'd')
	{
		darray = va_arg(ap, int *);
		while (i < arg.pre)
			ft_printf("[%d]", darray[i++]);
	}
	else
	{
		sarray = va_arg(ap, char **);
		while (i < arg.pre && sarray[i])
			ft_printf("[%s]", sarray[i++]);
	}
	ft_printf("\n");
}

static char		*redirect6(t_arg arg, va_list ap)
{
	if (arg.flag == 'a')
	{
		if ((arg.spe == 'd' || arg.spe == 's') && arg.pre > 0)
			print_array(arg, ap);
		return (ft_strdup(""));
	}
	return (NULL);
}

char			*redirect5(t_arg arg, va_list ap)
{
	if (arg.spe == 'b')
	{
		if (arg.flag == 0)
			return (ft_umax_itoa_base((unsigned int)va_arg(ap, void *), 2));
		else if (arg.flag == 'l')
			return (ft_umax_itoa_base((unsigned long)va_arg(ap, void *), 2));
		else if (arg.flag == 'L')
			return (ft_umax_itoa_base((unsigned long long)va_arg(ap, void *),
																			2));
		else if (arg.flag == 'h')
			return (ft_umax_itoa_base((unsigned short)va_arg(ap, void *), 2));
		else if (arg.flag == 'H')
			return (ft_umax_itoa_base((unsigned char)va_arg(ap, void *), 2));
		else if (arg.flag == 'j')
			return (ft_umax_itoa_base((uintmax_t)va_arg(ap, void *), 2));
		else if (arg.flag == 'z')
			return (ft_umax_itoa_base((size_t)va_arg(ap, void *), 2));
	}
	else
		return (redirect6(arg, ap));
	return (NULL);
}
