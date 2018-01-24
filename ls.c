/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:38:12 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/24 13:59:41 by abouvero         ###   ########.fr       */
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

void 	free_node(t_file *file)
{
	ft_strdel(&file->path);
	ft_strdel(&file->name);
	ft_strdel(&file->full_name);
	ft_memdel((void**)&file);
}

void 	del_list(t_file *file)
{
	if (!file)
		return ;
	if (file->next)
		del_list(file->next);
	free_node(file);
}

t_file	*list_del_spe(t_file *file)
{
	t_file	*del;
	int		i;

	i = -1;
	if (!file)
		return (NULL);
	while (++i < 2)
	{
		del = file;
		file = file->next;
		free_node(del);
	}
	return (file);
}

t_file	*fill_dir_list(t_file *file, char *path, char *name)
{
	t_file	*new;
	t_file	*beg;
	char	*save;

	beg = file;
	if (!(new = (t_file*)malloc(sizeof(t_file))))
		exit(1);
	new->path = ft_strdup(path);
	new->name = ft_strdup(name);
	save = ft_strjoin(new->path, new->name);
	new->full_name = ft_strdup(save);
	if (stat(new->full_name, &new->stat) == -1)
		open_err(new->full_name);
	else
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
	t_file		*beg;

	file = NULL;
	if (!(dir = opendir(path)))
		open_err(*path == '.' ? &path[2] : path);
	while (dir && (ret = readdir(dir)))
		file = (*ret->d_name == '.' && !(opt & ALL_OPT)) ?
				file : fill_dir_list(file, ft_strjoin(path, "/"), ret->d_name);
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
	ls(argv[1], 1);
	return (0);
}
