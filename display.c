/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:59 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 17:13:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	display(t_file *file)
{
	while (file)
	{
		ft_printf("%s\n", file->name);
		file = file->next;
	}
}

void 	long_display(t_file *f)
{
	char	*save;

	ft_printf("total %d\n", get_total(f));
	while (f)
	{
		save = get_rigths(ft_umax_itoa_base(f->stat.st_mode, 8));
		ft_printf("%s  %u %s  %s %*u %s %s\n", save,
				f->stat.st_nlink, getpwuid(f->stat.st_uid)->pw_name,
					getgrgid(f->stat.st_gid)->gr_name, 6, f->stat.st_size,
						ft_strsub(ctime(&f->stat.st_mtime), 4, 12), f->name);
		ft_strdel(&save);
		f = f->next;
	}
}
