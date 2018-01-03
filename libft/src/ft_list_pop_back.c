/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:24:48 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:08:07 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_list_pop_back(t_list *list)
{
	t_list	*beginning;
	t_list	*before;

	before = list;
	beginning = list;
	if (!list)
		return (NULL);
	if (!list->next)
		return (list);
	list = list->next;
	while (list->next)
	{
		list = list->next;
		before = before->next;
	}
	free(list);
	before->next = NULL;
	return (beginning);
}
