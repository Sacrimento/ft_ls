/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:39:55 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/22 13:23:15 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/includes/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

# define REC_OPT	1
# define LON_OPT	2
# define ALL_OPT	4
# define REV_OPT	8
# define TIM_OPT	16
# define COL_OPT	32

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

#endif
