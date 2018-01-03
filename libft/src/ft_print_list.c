/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:46:50 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/03 15:46:12 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_list(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_putchar('[');
		ft_putstr(list->content);
		ft_putstr("]\n");
		list = list->next;
	}
}
