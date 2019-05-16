/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_if_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:43:03 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 16:54:41 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_check_dir(char **arg)
{
	int i;
	DIR *dir;

	i = 0;
	while (arg[i])
	{
		errno = 0;
		dir = opendir(arg[i]);
		if (!dir && errno == ENOENT)
		{
			ft_putstr("ls: ");
			perror(arg[i]);
		}
		if (dir)
			closedir(dir);
		i++;
	}
}

void	ft_ls_check_if_file(char **arg, t_ops ops, int nb_arg)
{
	DIR *file;
	int i;
	int file_exist;

	i = 0;
	file_exist = 0;
	while (arg[i])
	{
		errno = 0;
		if ((file = opendir(arg[i])))
			closedir(file);
		if (!file && errno == ENOTDIR)
		{
			file_exist = 1;
			ft_ls_data_manipulation(file, ops, arg[i]);
		}
		i++;
	}
	ops.file_arg = 0;
	if (file_exist == 1 && nb_arg > 1)
		ft_putchar('\n');
}

void	ft_file_name_if_file(char *path, char *file)
{
	int i;
	int path_len;

	i = 0;
	path_len = ft_strlen(path);
	while (path_len >= 0)
	{
		if (path[path_len] == '/')
		{
			path_len++;
			ft_strcpy(file, path + path_len);
			return ;
		}
		path_len--;
	}
	ft_strcpy(file, path);
	return ;
}

void	ft_path_name_if_file(char *path)
{
	int		path_len;
	char	path_name[PATH_MAX];

	path_len = ft_strlen(path);
	while (path_len >= 0)
	{
		if (path[path_len] == '/')
		{
			ft_strncpy(path_name, path, path_len + 1);
			path_name[path_len + 1] = '\0';
			ft_strcpy(path, path_name);
			return ;
		}
		path_len--;
	}
	ft_strcpy(path, ".");
	return ;
}
