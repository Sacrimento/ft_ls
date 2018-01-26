/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:05:34 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 13:40:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void 	list_swap(t_file *file1, t_file *file2)
// {
// 	t_file	*tmp;
//
// 	file1->next = file2->next;
// 	file2->prev = file1->prev;
// 	if (file1->next)
// 		file1->next->prev = file1;
// 	if (file2->prev)
// 		file2->prev->next = file2;
// 	file2->next = file1;
// 	file1->prev = file2;
// }
//
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
//
// void 	rev_list(t_file *f)
// {
// 	(void)f;
// }
//
// t_file	*sort_list(t_file *f, int opt)
// {
// 	if (!f)
// 		return (f);
// 	opt & TIM_OPT ? sort_time(f) : sort_ascii(f);
// 	opt & REV_OPT ? rev_list(f) : 0;
// 	return (f);
// }

// t_file	*sort_insert(t_file *new, t_file *file, int opt)
// {
// 	t_file	*beg;
//
// 	beg = opt & TIM_OPT ? sort_time(new, file) : sort_ascii(new, file);
//
// 	t_file	*beg;
//
// 	beg = file;
// 	if (!file)
// 		return (new);
// 	else if (ft_strcmp(new->name, file->name) < 0)
// 	{
// 		new->next = file;
// 		return (new);
// 	}
// 	while (file->next && ft_strcmp(new->name, file->name) > 0)
// 		file = file->next;
// 	new->next = file->next;
// 	file->next = new;
// 	return (beg);
// }
