/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:59 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 13:40:57 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	display(t_file *file, int opt)
{
	while (file)
	{
		ft_printf("%s%s\n", file->path, file->name);
		file = file->next;
	}
}
