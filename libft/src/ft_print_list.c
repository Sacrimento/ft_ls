/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:46:50 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:09:31 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_list(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
}
