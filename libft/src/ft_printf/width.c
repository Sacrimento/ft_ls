/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:53:42 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/16 17:09:22 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*create_width(char c, int size)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strnew(size);
	if (c != '0')
		c = ' ';
	while (i < size)
		s[i++] = c;
	return (s);
}

char			*width(char *s, t_arg arg)
{
	char	*new_s;
	char	*width_s;

	if (arg.width > (int)ft_strlen(s))
	{
		width_s = create_width(arg.att.width_modi,
												arg.width - (int)ft_strlen(s));
		new_s = arg.att.width_modi != '-' ?
								ft_strjoin(width_s, s) : ft_strjoin(s, width_s);
		ft_strdel(&s);
		ft_strdel(&width_s);
		return (new_s);
	}
	return (s);
}
