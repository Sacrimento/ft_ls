/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:25:26 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:08:46 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(f)(t_list *elem))
{
	t_list	*tmp;
	t_list	**alst;

	if (!(alst = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	if (!list)
		return (NULL);
	if (!(*alst = f(list)))
		return (NULL);
	tmp = *alst;
	while (list->next)
	{
		if (!(tmp->next = f(list->next)))
			return (NULL);
		tmp = tmp->next;
		list = list->next;
	}
	return (*alst);
}
