/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:39:55 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/26 17:06:27 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

# define REC_OPT	1
# define LON_OPT	2
# define ALL_OPT	4
# define REV_OPT	8
# define TIM_OPT	16
# define COL_OPT	32

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef	struct			s_file
{
	char			*path;
	char			*name;
	char			*full_name;
	char			type;
	t_stat			stat;
	struct s_file	*next;
}						t_file;

char	get_type(char *oct);
int		get_opt(char *s);
void 	display(t_file *file);
void 	long_display(t_file *f);
t_file	*sort_time(t_file *new, t_file *file);
t_file	*sort_ascii(t_file *new, t_file *file);
t_file	*fill_dir_list(t_file *file, char *path, char *name, int opt);
void 	del_list(t_file *file);
void 	open_err(char *path);
char	*get_rigths(char *oct);
int		get_total(t_file *f);

#endif
