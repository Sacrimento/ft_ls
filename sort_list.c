/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:05:34 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/24 18:20:18 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	list_swap(t_file *file1, t_file *file2)
{
	t_file	*tmp;

	file1->next = file2->next;
	file2->prev = file1->prev;
	if (file1->next)
		file1->next->prev = file1;
	if (file2->prev)
		file2->prev->next = file2;
	file2->next = file1;
	file1->prev = file2;
}

void 	sort_ascii(t_file *f)
{
	t_file *beg;

	beg = f;
	while (f->next)
	{
		if (ft_strcmp(f->name, f->next->name) > 0)
		{
			list_swap(f, f->next);
			f = beg;
		}
		f = f->next;
	}
}

void 	sort_time(t_file *f)
{
	(void)f;
}

void 	rev_list(t_file *f)
{
	(void)f;
}

t_file	*sort_list(t_file *f, int opt)
{
	if (!f)
		return (f);
	opt & TIM_OPT ? sort_time(f) : sort_ascii(f);
	opt & REV_OPT ? rev_list(f) : 0;
	return (f);
}
