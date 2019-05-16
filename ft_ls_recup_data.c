/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_recup_data.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:37:44 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:02:15 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_full_path(t_ls *ls, char *d_name, char *path)
{
	ft_strcpy(ls->path, path);
	ft_strcat(ls->path, ft_strcmp(ls->path, "/") == 0 ? "" : "/");
	ft_strcat(ls->path, d_name);
}

void	ft_fill_list_next(t_stat info, t_ls *ls, int g, int o)
{
	t_passwd	*usr;
	t_group		*gr;

	if (!g)
	{
		usr = getpwuid(info.st_uid);
		if (usr == NULL)
			ls->user = ft_strdup(ft_itoa(info.st_uid));
		else
			ls->user = ft_strdup(usr->pw_name);
	}
	if (!o)
	{
		gr = getgrgid(info.st_gid);
		if (gr == NULL)
			ls->group = ft_strdup(ft_itoa(info.st_uid));
		else
			ls->group = ft_strdup(gr->gr_name);
	}
	if (S_ISCHR(info.st_mode) || S_ISBLK(info.st_mode))
	{
		ls->major = major(info.st_rdev);
		ls->minor = minor(info.st_rdev);
	}
}

int		ft_fill_list(struct dirent *r, t_ls *ls, t_ops ops, char *path)
{
	t_stat		info;
	int			tblocks;

	tblocks = 0;
	ft_strcpy(ls->name, r->d_name);
	ft_full_path(ls, r->d_name, path);
	lstat(ls->path, &info);
	ls->time = info.st_mtime;
	ls->d_type = r->d_type;
	ls->blocks = info.st_blocks;
	ft_ls_perm(info.st_mode, ls);
	if (ops.in)
		ls->inode = info.st_ino;
	if ((ops.l && r->d_name[0] != '.') || (ops.l && ops.a) || (ops.ua == 1
	&& ft_strcmp(ls->name, "..") != 0 && ft_strcmp(ls->name, ".") != 0))
	{
		ls->size = info.st_size;
		ls->nlink = info.st_nlink;
		ft_fill_list_next(info, ls, ops.g, ops.o);
		if ((ops.a == 1 && r->d_name[0] == '.') || (ops.l == 1 &&
		r->d_name[0] != '.') || ops.f == 1 ||
		(ops.ua && ft_strcmp(r->d_name, ".") && ft_strcmp(r->d_name, "..")))
			tblocks = info.st_blocks;
	}
	return (tblocks);
}

t_ops	ft_ls_read(DIR *dir, t_ops ops, char *path, t_ls **begin)
{
	t_ls			*to_add;
	t_ls			*curr;

	curr = NULL;
	to_add = NULL;
	ops.sp = ft_ls_init_space_struct();
	while ((ops.rep = readdir(dir)))
		if ((ops.file_arg && ft_strcmp(ops.file, ops.rep->d_name) == 0)
		|| !ops.file_arg)
		{
			if (!(to_add = (t_ls*)malloc(sizeof(t_ls))))
				exit(1);
			ft_bzero(to_add, sizeof(t_ls*));
			ops.tblocks += ft_fill_list(ops.rep, to_add, ops, path);
			ops.sp = ft_space(ops.sp, to_add, ops.rep, ops);
			ops.node_nb++;
			to_add->next = NULL;
			if (curr)
				curr->next = to_add;
			curr = to_add;
			*begin = !*begin ? to_add : *begin;
		}
	return (ops);
}

int		ft_ls_data_manipulation(DIR *dir, t_ops ops, char *path)
{
	t_ls *list;
	t_ls *subdir;

	list = NULL;
	subdir = NULL;
	ops.node_nb = 0;
	ops.tblocks = 0;
	if (!dir)
	{
		ft_file_name_if_file(path, ops.file);
		ft_path_name_if_file(path);
		dir = opendir(path);
		ops.file_arg = 1;
	}
	ops = ft_ls_read(dir, ops, path, &list);
	if (!ops.f)
		ft_sort_list(&list, ops.node_nb, ops.r, ops.t);
	subdir = list;
	ft_ls_display(list, ops, ops.sp, path);
	closedir(dir);
	if (ops.file_arg)
		return (0);
	if (ops.ur)
		ft_ls_recursive(subdir, path, ops, ops.node_nb);
	return (0);
}
