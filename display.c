/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:25:59 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 18:32:00 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	display(t_file *file, int opt)
{
	while (file)
	{
		ft_printf("%s\n", file->name);
		file = file->next;
	}
}
