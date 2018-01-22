/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:00:48 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 13:23:07 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void 	opt_err(char c)
{
	ft_printf("./ft_ls : illegal option -- %c\n", c);
	ft_printf("usage : ./ft_ls [-GRalrt] [file ...]\n");
	exit(1);
}

int		get_opt(char *s)
{
	int		opt;

	opt = 0;
	while (*s)
	{
		if (*s == 'R')
			opt |= REC_OPT;
		else if (*s == 'l')
			opt |= LON_OPT;
		else if (*s == 'a')
			opt |= ALL_OPT;
		else if (*s == 'r')
			opt |= REV_OPT;
		else if (*s == 't')
			opt |= TIM_OPT;
		else if (*s == 'G')
			opt |= COL_OPT;
		else
			opt_err(*s);
		s++;
	}
	return (opt);
}
