/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:29:46 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/19 16:45:42 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		free_char_array(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		ft_strdel(&(tab[i++]));
	ft_strdel(&(tab[i]));
	ft_memdel((void**)tab);
}

static int		write_color(char *str, char **colors)
{
	int		i;
	int		modifier;

	i = 0;
	while (ft_strcmp(str, colors[i]) != 0)
		i++;
	if (i <= 17)
		modifier = 30;
	else
	{
		i = 0;
		modifier = 0;
	}
	if (colors[i] != 0)
	{
		ft_printf("\x1b[%dm", modifier + i);
		ft_strdel(&str);
		return (modifier + i == 0 ? 5 : i);
	}
	ft_strdel(&str);
	return (0);
}

int				colorise(char *str)
{
	char	**colors;
	int		i;

	i = -1;
	colors = ft_strsplit("blk:red:grn:yel:blu:mag:cya:wht:void:void:bblk:bred:\
									bgrn:byel:bblu:bmag:bcya:bwht:eoc", ':');
	while (str[++i] && i < 6)
	{
		if (str[i] == '>' && i < 6)
		{
			if (write_color(ft_strsub(str, 1, i - 1), colors))
			{
				free_char_array(colors);
				return (i + 1);
			}
		}
	}
	free_char_array(colors);
	write(1, "<", 1);
	return (1);
}
