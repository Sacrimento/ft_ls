/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:21:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 17:12:44 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

static int			create_line(char **line, t_fd_list *current)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*current->str)
	{
		while (current->str[i] != '\n' && current->str[i])
			i++;
		*line = ft_strsub(current->str, 0, i);
		tmp = ft_strsub(current->str, i + 1, ft_strlen(current->str) - i);
		ft_memdel((void**)&current->str);
		current->str = tmp;
		return (1);
	}
	return (0);
}

static char			*ft_strjoin_custom(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new_s = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	free(s1);
	new_s[j] = '\0';
	return (new_s);
}

static	int			ft_read(t_fd_list *current, int fd)
{
	int		ret;
	char	*buff;

	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && *buff)
	{
		buff[ret] = '\0';
		current->str = ft_strjoin_custom(current->str, buff);
		if (ft_memchr(current->str, '\n', ft_strlen(current->str)))
			break ;
	}
	free(buff);
	if (ret < 0)
		return (-1);
	return (0);
}

static t_fd_list	*get_line_by_fd(t_fd_list **list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new;

	current = *list;
	if (current->fd == fd)
		return (current);
	while (current->next)
	{
		if (current->next->fd == fd)
			return (current->next);
		current = current->next;
	}
	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	if (current)
		current->next = new;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_fd_list	*list;
	t_fd_list			*current;

	if (!list)
	{
		if (!(list = (t_fd_list*)malloc(sizeof(t_fd_list))))
			return (-1);
		list->fd = -1337;
		list->next = NULL;
	}
	if (!(current = get_line_by_fd(&list, fd)) || fd < 0 || !line ||
							BUFF_SIZE <= 0 || ft_read(current, fd) == -1)
		return (-1);
	if (create_line(line, current))
		return (1);
	free(current->str);
	current->str = ft_strnew(0);
	return (0);
}
