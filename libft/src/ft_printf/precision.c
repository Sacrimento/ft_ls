/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:35:50 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:08:54 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*create_0str(int size)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strnew(size);
	while (i < size)
		s[i++] = '0';
	s[i] = '\0';
	return (s);
}

char			*precision(char *str, t_arg arg)
{
	char	*new_s;
	char	*zero_s;
	int		sign;

	sign = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	if ((arg.pre == 0 && arg.spe != 'd' && arg.spe != 'i' && arg.spe != 'o') ||
	(arg.pre == 0 && (arg.spe == 'd' || arg.spe == 'i' || arg.spe == 'o') &&
																*str == '0'))
	{
		ft_bzero((void*)str, ft_strlen(str));
		return (str);
	}
	if (arg.spe == 's' && arg.pre < (int)ft_strlen(str))
		str[arg.pre == -1 ? ft_strlen(str) + 1 : arg.pre] = '\0';
	else if ((arg.spe == 'd' || arg.spe == 'i' || arg.spe == 'o' || arg.spe ==
	'p' || arg.spe == 'u' || arg.spe == 'x' || arg.spe == 'X' || arg.spe == 'O')
				&& (arg.pre > (int)ft_strlen(str) - sign) && arg.flag != 'a')
	{
		zero_s = create_0str(arg.pre - (ft_strlen(str) - sign));
		new_s = ft_strjoin(zero_s, str);
		ft_strdel(&str);
		ft_strdel(&zero_s);
		return (new_s);
	}
	return (str);
}
