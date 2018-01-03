/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 09:54:15 by abouvero          #+#    #+#             */
/*   Updated: 2018/01/03 17:31:44 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int		printdir(char *path);
int		can_open(char *path);

int		main(int argc, char **argv)
{
	(void)argc;

	//printf("%d\n", can_open("./libft/obj/"));
	printdir(argv[1]);


	/*DIR		*dir;
	struct dirent *ret;

	dir = opendir(argv[1]);

	if (!dir)
	{
		perror("");
		return (1);
	}

	while ((ret = readdir(dir)))
	{
		printf("%llu > %s\n", ret->d_ino, ret->d_name);
		printf("%c\n", ret->d_type);
		//printf("%d\n", ret->d_off);
		printf("%hu\n", ret->d_reclen);
	}
	// printf("open\n");
	closedir(dir);*/
	return (0);
}

/*int		printdir(char *path)
{
	DIR				*dir;
	struct dirent	*ret;

	if (!(dir = opendir(path)))
		return (errno);
	while ((ret = readdir(dir)))
	{
		if (ret->d_name[0] != '.')
		{
			printdir(ret->d_name);
			printf("%s\t", ret->d_name);
		}
	}
	printf("\n");
	return (0);
}*/

void 	del(void *content, size_t size)
{
	ft_memdel(&content);
	(void)size;
}

int		can_open(char *path)
{
	DIR		*dir;

	if (!(dir = opendir(path)))
		return (0);
	closedir(dir);
	return (1);
}

int		printdir(char *path)
{
	DIR				*dir;
	struct dirent	*ret;
	t_list			*list = NULL;
	t_list			*beg;

	path = ft_strcat(path, "/");
	if (!(dir = opendir(path)))
		return (errno);
	if (strcmp("./", path) != 0)
		printf("%s:\n", path);
	while ((ret = readdir(dir)))
	{
		if (ret->d_name[0] != '.')
		{
			if (can_open(ft_strjoin(path, ret->d_name)))
				list = ft_list_push_back(ret->d_name, list);
			printf("%s\n", ret->d_name);
		}
	}
	closedir(dir);
	beg = list;
	while (list)
	{
		printf("\n");
		printdir(ft_strjoin(path, list->content));
		list = list->next;
	}
	ft_lstdel(&beg, del);
	return (0);
}
