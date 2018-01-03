/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:07:14 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:07:57 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	unsigned int	size;

	size = (unsigned int)ft_list_size(begin_list);
	i = 1;
	if (size < nbr)
		return (NULL);
	while (i < nbr)
	{
		if (begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
