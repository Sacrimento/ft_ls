/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:39:55 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/19 18:11:08 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/includes/libft.h"
#include <dirent.h>
#include <sys/stat.h>

typedef struct			s_opt
{
	int		l;
	int		r;
	int		rr;
	int		gg;
	int		a;
	int		t;
}						t_opt;

typedef struct dirent	t_dirent;

#endif
