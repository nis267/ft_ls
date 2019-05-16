/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_part_2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 16:39:10 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 17:03:46 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_display_perm(char *perm)
{
	ft_putstr(perm);
	if (ft_strlen(perm) == 11)
		ft_putchar(' ');
	else
		ft_putstr("  ");
}

int		ft_ls_display_tblocks(char *name, t_ops ops)
{
	if (((ops.l == 1 && ft_strlen(name) > 0 && name[0] != '.' &&
	!ops.file_arg) || ((ops.a == 1 || ops.f == 1) && name[0] == '.' &&
	ops.l == 1 && !ops.file_arg) || ((ops.ua == 1 && ops.l == 1 &&
	ft_strcmp(name, "..") != 0) && ft_strcmp(name, ".") != 0 && !ops.file_arg)))
	{
		ft_putstr("total ");
		ft_ls_display_param(ft_itoa(ops.tblocks), 0, 2);
		ft_putchar('\n');
		ops.l = 2;
	}
	if (ops.file_arg && ops.l == 1)
		ops.l = 2;
	return (ops.l);
}

void	ft_ls_display_symbolic_link(char *path)
{
	char	buf[PATH_MAX];
	int		size;

	size = readlink(path, buf, PATH_MAX);
	buf[size] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void	ft_ls_display_major_minor(int min, int maj, size_t smin, size_t smaj)
{
	unsigned long i;

	i = 0;
	ft_putchar(' ');
	while (i < (smaj - ft_strlen(ft_ltoa(maj))))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(ft_ltoa(maj));
	ft_putchar(',');
	ft_putchar(' ');
	ft_ls_display_param(ft_ltoa(min), smin, 0);
}
