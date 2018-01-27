/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:00:48 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/27 13:05:56 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	opt_err(char c)
{
	ft_putstr_fd("./ft_ls : illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage : ./ft_ls [-GRalrt] [file ...]\n", 2);
	exit(1);
}

int		get_total(t_file *f)
{
	int		i;

	i = 0;
	while (f)
	{
		i += f->stat.st_blocks;
		f = f->next;
	}
	return (i);
}

char	*get_rigths(char *oct)
{
	int		i;
	int		j;
	char	num;
	char	*ret;

	i = 3;
	j = 0;
	ret = ft_strnew(10);
	ret[0] = get_type(ft_strdup(oct));
	while (i != 0)
	{
		num = oct[ft_strlen(oct) - i--];
		if (num == '0')
			ft_strcpy(&ret[j * 3 + 1], "---");
		else if (num == '1')
			ft_strcpy(&ret[j * 3 + 1], "--x");
		else if (num == '2')
			ft_strcpy(&ret[j * 3 + 1], "-w-");
		else if (num == '3')
			ft_strcpy(&ret[j * 3 + 1], "-wx");
		else if (num == '4')
			ft_strcpy(&ret[j * 3 + 1], "r--");
		else if (num == '5')
			ft_strcpy(&ret[j * 3 + 1], "r-x");
		else if (num == '6')
			ft_strcpy(&ret[j * 3 + 1], "rw-");
		else if (num == '7')
			ft_strcpy(&ret[j * 3 + 1], "rwx");
		j++;
	}
	ft_strdel(&oct);
	return (ret);
}

char	get_type(char *oct)
{
	char	*type;
	char	ret;

	type = ft_strsub(oct, 0, ft_strlen(oct) - 3);
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
