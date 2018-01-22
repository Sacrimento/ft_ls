/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:00:48 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 20:20:28 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	opt_err(char c)
{
	ft_printf("./ft_ls : illegal option -- %c\n", c);
	ft_printf("usage : ./ft_ls [-GRalrt] [file ...]\n");
	exit(1);
}

char	get_type(char *oct)
{
	char	*type;
	char	ret;

	type = ft_strsub(oct, 0, ft_strlen(oct) - 3);
	//type = ft_strlen(oct) > 2 ? ft_strsub(oct, 0, ft_strlen(oct) - 3) : ft_strdup("100"); // ??????
	if (!ft_strcmp("10", type))
		ret = 'p';
	else if (!ft_strcmp("20", type))
		ret = 'c';
	else if (!ft_strcmp("40", type))
		ret = 'd';
	else if (!ft_strcmp("60", type))
		ret = 'b';
	else if (!ft_strcmp("100", type))
		ret= '-';
	else if (!ft_strcmp("120", type))
		ret = 'l';
	else if (!ft_strcmp("140", type))
		ret = 's';
	ft_strdel(&type);
	ft_strdel(&oct);
	return (ret);
}

int		get_opt(char *s)
{
	int		opt;

	opt = 0;
	while (*s)
	{
		if (*s == 'R')
			opt |= REC_OPT;
		else if (*s == 'l')
			opt |= LON_OPT;
		else if (*s == 'a')
			opt |= ALL_OPT;
		else if (*s == 'r')
			opt |= REV_OPT;
		else if (*s == 't')
			opt |= TIM_OPT;
		else if (*s == 'G')
			opt |= COL_OPT;
		else
			opt_err(*s);
		s++;
	}
	return (opt);
}
