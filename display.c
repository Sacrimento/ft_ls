/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:59 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 16:51:54 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	display(t_file *file, int opt)
{
	while (file)
	{
		ft_printf("FILE : %s | TYPE : %c\n", file->name, file->type);
		file = file->next;
	}
}
