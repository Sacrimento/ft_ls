/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:59 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/27 12:53:09 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_digits_dec(unsigned int nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr -= nbr % 10;
		nbr /= 10;
		i++;
	}
	return (i);
}

int		get_max_size(t_file *f)
{
	int		max;
	int		new;

	max = 0;
	while (f)
	{
		max = (new = count_digits_dec(f->stat.st_size)) > max ? new : max;
		f = f->next;
	}
	return (max);
}

void 	display(t_file *file, int first)
{
	if (!first)
		ft_printf("%s:\n", file->path);
	while (file)
	{
		ft_printf("%s\n", file->name);
		file = file->next;
	}
}

void 	long_display(t_file *f, int first)
{
	char	*save;
	int		max;

	max = get_max_size(f);
	if (!first)
		ft_printf("%.*s:\n", ft_strlen(f->path) - 1, f->path);
	ft_printf("total %d\n", get_total(f));
	while (f)
	{
		save = get_rigths(ft_umax_itoa_base(f->stat.st_mode, 8));
		ft_printf("%s  %u %s  %s  %*u %s %s\n", save,
				f->stat.st_nlink, getpwuid(f->stat.st_uid)->pw_name,
					getgrgid(f->stat.st_gid)->gr_name, max, f->stat.st_size,
						ft_strsub(ctime(&f->stat.st_mtime), 4, 12), f->name);
		ft_strdel(&save);
		f = f->next;
	}
}
