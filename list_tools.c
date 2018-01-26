/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:05:34 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 16:34:18 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_file	*fill_dir_list(t_file *file, char *path, char *name, int opt)
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
	return (opt & TIM_OPT ? sort_time(new, file) : sort_ascii(new, file));
}

t_file	*sort_ascii(t_file *new, t_file *file)
{
	t_file	*beg;

	beg = file;
	if (!file)
		return (new);
	else if (ft_strcmp(new->name, file->name) < 0)
	{
		new->next = file;
		return (new);
	}
	while (file->next && ft_strcmp(new->name, file->next->name) > 0)
		file = file->next;
	new->next = file->next;
	file->next = new;
	return (beg);
}

t_file	*sort_time(t_file *new, t_file *file)
{
	t_file	*beg;

	beg = file;
	if (!file)
		return (new);
	else if (new->stat.st_mtime > file->stat.st_mtime)
	{
		new->next = file;
		return (new);
	}
	while (file->next && new->stat.st_mtime < file->next->stat.st_mtime)
		file = file->next;
	new->next = file->next;
	file->next = new;
	return (beg);
}
