/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:38:12 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 17:19:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		open_err(char *path)
{
	ft_printf("./ft_ls : %s : no such file or directory\n", path);
	exit(1);
	return (0);
}

void 	del_list(t_file *file)
{
	if (!file)
		return ;
	if (file->next)
		del_list(file->next);
	ft_strdel(&file->path);
	ft_strdel(&file->name);
	ft_memdel((void**)&file);
}

t_file	*fill_dir_list(t_file *file, char *path, char *name)
{
	t_file	*new;
	t_file	*beg;
	char	*save;

	beg = file;
	if (!(new = (t_file*)malloc(sizeof(t_file))))
		exit(1);
	save = ft_strjoin(path, name);
	new->path = ft_strdup(path);
	new->name = ft_strdup(save);
	stat(new->name, &new->stat);
	new->type = get_type(ft_umax_itoa_base(new->stat.st_mode, 8));
	new->next = NULL;
	ft_strdel(&save);
	ft_strdel(&path);
	if (!file)
		return (new);
	while (file->next)
		file = file->next;
	file->next = new;
	return (beg);
}

int		ls(char *path, int opt)
{
	DIR			*dir;
	t_dirent	*ret;
	t_file		*file;

	file = NULL;
	if (!(dir = opendir(path)))
		return (open_err(path));
	while ((ret = readdir(dir)))
		file = fill_dir_list(file, ft_strjoin(path, "/"), ret->d_name);
	display(file, opt);
	while (file && (opt & REC_OPT))
	{
		file->type == 'd' ? ls(file->name, opt) : 0;
		file = file->next;
	}
	del_list(file);
	return (0);
}

int		main(int argc, char **argv)
{
	ls(argv[1], 0);
	return (0);
}
