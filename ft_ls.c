/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:49:23 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/19 18:51:21 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		bas_ls(char	 *path, t_opt *opt)
{
	DIR			*dir;
	t_dirent	*ret;

	if (!(dir = opendir(path)))
		return (2);
	while ((ret = readdir(dir)))
		if (*ret->d_name != '.' && !opt->a)
			ft_printf("%-*s", 16, ret->d_name);
	printf("\n");
	return (0);
}

void 	opt_to_zero(t_opt *opt)
{
	opt->l = 0;
	opt->r = 0;
	opt->rr = 0;
	opt->gg = 0;
	opt->a = 0;
	opt->t = 0;
}

void 	init_opt(t_opt *opt, char *s)
{
	while (*s)
	{
		if (*s == 'l')
			opt->l = 1;
		else if (*s == 'r')
			opt->r = 1;
		else if (*s == 'a')
			opt->a = 1;
		else if (*s == 't')
			opt->t = 1;
		else if (*s == 'R')
			opt->rr = 1;
		else if (*s == 'G')
			opt->gg = 1;
		else
		{
			ft_printf("./ft_ls : illegal option -- %c\n", *s);
			ft_printf("usage : ./ft_ls [-GRalrt] [file ...]\n");
			exit(1);
		}
		s++;
	}
}

int		ft_ls(char *s, t_opt *opt)
{
	ft_printf("[%d%d%d%d%d%d] [%s]\n", opt->l, opt->r, opt->rr, opt->gg, opt->a, opt->t, s);
	// if (opt->rr)
	// 	rec_ls(s);
	bas_ls(s, opt);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	t_opt	opt;

	i = 0;
	opt_to_zero(&opt);
	if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
		return (ft_ls(".", &opt));
	if (*argv[1] == '-')
		init_opt(&opt, ++argv[++i]);
	while (++i < argc)
		if (!(ft_ls(argv[i], &opt)))
			return (1);
	return (0);
}
