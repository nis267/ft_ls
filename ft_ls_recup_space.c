/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_recup_space.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:46:07 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:05:42 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ft_nb_len(long param)
{
	size_t i;

	i = 0;
	if (param == 0)
		i++;
	while (param > 0)
	{
		param /= 10;
		i++;
	}
	return (i);
}

t_space		ft_space_next(t_space s, t_ls *to_add, t_ops ops)
{
	s.ssize = ft_nb_len(to_add->size) > s.ssize ?
		ft_nb_len(to_add->size) : s.ssize;
	s.sli = ft_nb_len(to_add->nlink) > s.sli ? ft_nb_len(to_add->nlink) : s.sli;
	if (to_add->user && !ops.g)
		s.susr = ft_strlen(to_add->user) > s.susr ?
			ft_strlen(to_add->user) : s.susr;
	if (to_add->group && !ops.o)
		s.sgrp = ft_strlen(to_add->group) > s.sgrp ?
			ft_strlen(to_add->group) : s.sgrp;
	return (s);
}

t_space		ft_space(t_space s, t_ls *to_add, t_dirent *rep, t_ops ops)
{
	if (ops.s)
		s.sblocks = ft_nb_len(to_add->blocks) > s.sblocks ?
		ft_nb_len(to_add->blocks) : s.sblocks;
	if (ops.in)
		s.sino = ft_nb_len(to_add->inode) > s.sino ?
		ft_nb_len(to_add->inode) : s.sino;
	if ((ops.a && rep->d_name[0] == '.') || rep->d_name[0] != '.' || (ops.ua
	&& ft_strcmp(rep->d_name, ".") != 0 && ft_strcmp(rep->d_name, ".") != 0))
		s.sname = ft_strlen(to_add->name) > s.sname ? ft_strlen(to_add->name)
		: s.sname;
	if ((ops.a == 1 && rep->d_name[0] == '.') || ((ops.l || ops.g) == 1
	&& rep->d_name[0] != '.') || ops.f == 1 || (ops.ua &&
	ft_strcmp(rep->d_name, ".") != 0 && ft_strcmp(rep->d_name, "..") != 0))
	{
		if (to_add->perm[0] == 'b' || to_add->perm[0] == 'c')
		{
			s.sminor = ft_nb_len(to_add->minor) > s.sminor ?
				ft_nb_len(to_add->minor) : s.sminor;
			s.smajor = ft_nb_len(to_add->major) > s.smajor ?
				ft_nb_len(to_add->major) : s.smajor;
		}
		s = ft_space_next(s, to_add, ops);
	}
	return (s);
}
