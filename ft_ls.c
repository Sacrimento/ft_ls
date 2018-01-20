/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:49:23 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/20 18:56:43 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	get_type(char *type)
{
	if (!ft_strcmp("10", type))
		write(1, "p", 1);
	else if (!ft_strcmp("20", type))
		write(1, "c", 1);
	else if (!ft_strcmp("40", type))
		write(1, "d", 1);
	else if (!ft_strcmp("60", type))
		write(1, "b", 1);
	else if (!ft_strcmp("100", type))
		write(1, "-", 1);
	else if (!ft_strcmp("120", type))
		write(1, "l", 1);
	else if (!ft_strcmp("140", type))
		write(1, "s", 1);
	ft_strdel(&type);
}

void 	write_rigths(char *oct)
{
	int		i;
	char	num;

	i = 3;
	get_type(ft_strsub(oct, 0, ft_strlen(oct) - 3));
	while (i != 0)
	{
		num = oct[ft_strlen(oct) - i--];
		if (num == '0')
			write(1, "---", 3);
		else if (num == '1')
			write(1, "--x", 3);
		else if (num == '2')
			write(1, "-w-", 3);
		else if (num == '3')
			write(1, "-wx", 3);
		else if (num == '4')
			write(1, "r--", 3);
		else if (num == '5')
			write(1, "r-x", 3);
		else if (num == '6')
			write(1, "rw-", 3);
		else if (num == '7')
			write(1, "rwx", 3);
	}
	ft_strdel(&oct);
}

int		bas_ls(char	 *path, t_opt *opt)
{
	DIR			*dir;
	t_dirent	*ret;
	t_stat		buff;

	if (!(dir = opendir(path)))
		return (2);
	while ((ret = readdir(dir)))
		if (*ret->d_name != '.' && !opt->a)
		{
			stat(ret->d_name, &buff);
			write_rigths(ft_umax_itoa_base(buff.st_mode, 8));
			ft_printf("  %u %s  %s %*u %s %s\n", buff.st_nlink, getpwuid(buff.st_uid)->pw_name,
			getgrgid(buff.st_gid)->gr_name, 6, buff.st_size, ft_strsub(ctime(&buff.st_mtime), 4, 12), ret->d_name);
		}
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
