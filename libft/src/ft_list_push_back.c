/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:33:54 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/03 13:25:46 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_list_push_back(void *data, t_list *list)
{
	t_list	*beginning;
	t_list	*elem;

	beginning = list;
	if (!(elem = ft_lstnew(data, sizeof(data))))
		return (NULL);
	if (!list)
		return (elem);
	while (list->next)
		list = list->next;
	list->next = elem;
	return (beginning);
}
