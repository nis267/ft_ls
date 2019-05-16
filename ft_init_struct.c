/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 18:10:48 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:10:52 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_space			ft_ls_init_space_struct(void)
{
	t_space s;

	s.sname = 0;
	s.sli = 0;
	s.ssize = 0;
	s.susr = 0;
	s.sgrp = 0;
	s.sino = 0;
	s.smajor = 0;
	s.sminor = 0;
	s.sblocks = 0;
	return (s);
}

t_ops			ft_ls_init_ops_struct(void)
{
	t_ops ops;

	ops.i = 1;
	ops.ur = 0;
	ops.l = 0;
	ops.r = 0;
	ops.t = 0;
	ops.a = 0;
	ops.ug = 0;
	ops.in = 0;
	ops.f = 0;
	ops.g = 0;
	ops.ua = 0;
	ops.s = 0;
	ops.o = 0;
	ops.file_arg = 0;
	return (ops);
}
