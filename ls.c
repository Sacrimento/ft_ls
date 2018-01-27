/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:38:12 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/27 12:45:40 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	open_err(char *path)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}

void 	rev_list(t_file **f)
{
	t_file	*rest;
	t_file	*first;

	if (*f == NULL)
		return ;
	first = *f;
	rest = first->next;
	if (rest == NULL)
		return ;
	rev_list(&rest);
	first->next->next = first;
	first->next = NULL;
	*f = rest;
}

int		ls(char *path, int opt, int first)
{
	DIR			*dir;
	t_dirent	*ret;
	t_file		*file;
	t_file		*beg;

	file = NULL;
	if (!(dir = opendir(path)))
		open_err(path);
	while (dir && (ret = readdir(dir)))
		file = (*ret->d_name == '.' && !(opt & ALL_OPT)) ?
			file : fill_dir_list(file, ft_strjoin(path, "/"), ret->d_name, opt);
	dir ? closedir(dir) : 0;
	opt & REV_OPT ? rev_list(&file) : 0;
	beg = file;
	opt & LON_OPT ? long_display(file, first) : display(file, first);
	while (file && (opt & REC_OPT))
	{
		(file->type == 'd' && (ft_strcmp(file->name, ".") &&
				ft_strcmp(file->name, ".."))) ? ls(file->full_name, opt, 0) : 0;
		file->next ? ft_printf("\n") : 0;
		file = file->next;
	}
	dir ? del_list(beg) : 0;
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		opt;

	if (argc == 1 || (argc == 2 && *argv[1] == '-'))
		return (ls(".", get_opt(argv[1] + 1), 1));
	opt = *argv[1] == '-' ? get_opt(argv[1] + 1) : 0;
	i = *argv[1] == '-' ? 1 : 0;
	//argv = sort_type(argv)
	while (++i < argc)
	{
		ls(argv[i], opt, 0);
		i + 1 == argc ? 0 : ft_printf("\n");
	}
	return (0);
}
