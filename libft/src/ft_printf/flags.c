/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:26:16 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:08:41 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*space_flag(char *s)
{
	char	*new_s;

	if (s[0] == '-')
		return (s);
	new_s = ft_strjoin(" ", s);
	ft_strdel(&s);
	return (new_s);
}

static char		*plus_flag(char *s)
{
	char	*new_s;

	if (s[0] != '-' && s[0] != '+')
	{
		new_s = ft_strjoin("+", s);
		ft_strdel(&s);
		return (new_s);
	}
	return (s);
}

static char		*diese_flag(char *s, t_arg arg)
{
	char	*new_s;

	if ((arg.spe == 'o' || arg.spe == 'O') && s[0] != '0')
		new_s = ft_strjoin("0", s);
	else if (arg.spe == 'x' || arg.spe == 'p')
		new_s = ft_strjoin("0x", s);
	else if (arg.spe == 'X')
		new_s = ft_strjoin("0X", s);
	else
		return (s);
	ft_strdel(&s);
	return (new_s);
}

char			*flags(char *s, t_arg arg)
{
	s = (arg.att.diese || arg.spe == 'p') ? diese_flag(s, arg) : s;
	if (arg.att.sign == '+' && (arg.spe == 'd' ||
											arg.spe == 'i' || arg.spe == 'D'))
		s = plus_flag(s);
	s = (arg.att.sign == ' ' && (arg.spe != 's' && arg.spe != 'S'))
															? space_flag(s) : s;
	return (s);
}
