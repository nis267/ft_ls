/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_part_1.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 18:10:33 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:10:36 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_display_list(t_ls *ls, t_space s, int g, int o)
{
	ft_ls_display_perm(ls->perm);
	ft_ls_display_param(ft_ltoa(ls->nlink), s.sli, 0);
	if (g && o)
		ft_putstr("  ");
	if (!g)
		ft_ls_display_param(ls->user, s.susr, 1);
	if (!o)
		ft_ls_display_param(ls->group, s.sgrp, 1);
	if (ls->perm[0] == 'b' || ls->perm[0] == 'c')
		ft_ls_display_major_minor(ls->minor, ls->major, s.sminor, s.smajor);
	else
		ft_ls_display_param(ft_ltoa(ls->size), s.ssize, 0);
	ls_display_time(ls->time);
}

char	*ft_if_file_concat(char *file, char *path)
{
	if (ft_strcmp(path, ".") == 0)
		return (file);
	else
		ft_strcat(path, file);
	return (path);
}

void	ft_ls_display_options(t_ls *ls, t_ops ops, t_space s, char *path)
{
	if (ops.in)
		ft_ls_display_param(ft_ltoa(ls->inode), s.sino, 0);
	if (ops.s)
		ft_ls_display_param(ft_ltoa(ls->blocks), s.sblocks, 0);
	if (ops.l == 2)
		ft_ls_display_list(ls, s, ops.g, ops.o);
	if (ops.file_arg)
	{
		ft_strcpy(ls->name, ft_if_file_concat(ops.file, path));
		ft_bzero(path, ft_strlen(path));
	}
	if (ops.ug || (ops.file_arg && ops.ug == 1))
		ft_ls_color(ls->name, ls->d_type, ls->perm);
	else
		ft_putstr(ls->name);
	if (ops.l == 2 && ls->d_type == 10)
		ft_ls_display_symbolic_link(ls->path);
	ft_putchar('\n');
}

t_ls	*ft_ls_free_node(t_ls *ls)
{
	t_ls *tmp;

	if (!ls)
		return (NULL);
	tmp = ls->next;
	free(ls);
	ls = NULL;
	return (tmp);
}

void	ft_ls_display(t_ls *ls, t_ops ops, t_space sp, char *path)
{
	sp.ssize = (sp.sminor + sp.smajor) > 0 ? (sp.sminor + sp.smajor) + 3
	: sp.ssize;
	while (ls)
	{
		ops.l = ft_ls_display_tblocks(ls->name, ops);
		if ((ops.a) || (ls->name[0] != '.') ||
		((ops.ua == 1 && ft_strcmp(ls->name, "..") != 0)
		&& ft_strcmp(ls->name, ".") != 0))
		{
			ft_ls_display_options(ls, ops, sp, path);
			if (ops.ur)
				ls = ls->next;
			else
				ls = ft_ls_free_node(ls);
		}
		else
		{
			if (ops.ur)
				ls = ls->next;
			else
				ls = ft_ls_free_node(ls);
		}
	}
}
