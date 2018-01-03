/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:28:58 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:08:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_list_push_front(void *data, t_list *list)
{
	t_list	*elem;

	if (!(elem = ft_lstnew(data, sizeof(data) + ft_strlen((char*)data))))
		return (NULL);
	elem->next = list;
	return (elem);
}
