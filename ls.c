/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:38:12 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 16:32:08 by abouvero         ###   ########.fr       */
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

int		ls(char *path, int opt)
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
	opt & REV_OPT ? rev_list(&file) : 0;
	beg = file;
	dir ? display(file, opt) : 0;
	while (file && (opt & REC_OPT))
	{
		(file->type == 'd' && (ft_strcmp(file->name, ".") &&
				ft_strcmp(file->name, ".."))) ? ls(file->full_name, opt) : 0;
		file = file->next;
	}
	dir ? del_list(beg) : 0;
	dir ? closedir(dir) : 0;
	return (0);
}

int		main(int argc, char **argv)
{
	ls(argv[1], ft_atoi(argv[2]));
	return (0);
}
