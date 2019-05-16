/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 17:52:06 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 16:56:35 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_recursive(t_ls *subdir, char *path, t_ops ops, int node_nb)
{
	char tmp[PATH_MAX];

	while (subdir)
	{
		if (((subdir->d_type == 4 && (ft_strcmp(subdir->name, ".") != 0) &&
			(ft_strcmp(subdir->name, "..") != 0)) && ops.a) ||
			(subdir->name[0] != '.' && subdir->d_type == 4))
		{
			ft_strcpy(tmp, path);
			ft_strcat(tmp, ft_strcmp(path, "/") == 0 ? "" : "/");
			ft_strcat(tmp, subdir->name);
			ft_ls(tmp, ops, node_nb);
		}
		subdir = ft_ls_free_node(subdir);
	}
}

int		ft_ls(char *arg, t_ops ops, int nb_arg)
{
	char	path[PATH_MAX];
	DIR		*dir;

	ft_strcpy(path, arg);
	dir = opendir(path);
	if (nb_arg > 1 && ft_strlen(path) > 0 && dir)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if (!dir)
	{
		if (errno != ENOENT && errno != ENOTDIR)
		{
			ft_putstr("ls: ");
			perror(path);
		}
	}
	else
		ft_ls_data_manipulation(dir, ops, path);
	if (nb_arg > 1 && dir)
		ft_putchar('\n');
	return (0);
}

t_ops	ft_ls_flag(char flag, t_ops ops)
{
	ops.ur = flag == 'R' ? 1 : ops.ur;
	ops.t = flag == 't' ? 1 : ops.t;
	ops.r = flag == 'r' ? 1 : ops.r;
	ops.ug = flag == 'G' ? 1 : ops.ug;
	ops.g = flag == 'g' ? 1 : ops.g;
	ops.l = flag == 'l' || ops.g ? 1 : ops.l;
	ops.in = flag == 'i' ? 1 : ops.in;
	ops.f = flag == 'f' ? 1 : ops.f;
	ops.a = flag == 'a' || ops.f ? 1 : ops.a;
	ops.ua = flag == 'A' ? 1 : ops.ua;
	ops.s = flag == 's' ? 1 : ops.s;
	ops.o = flag == 'o' ? 1 : ops.o;
	!ft_strchr("RltraGfgiAsio", flag) ? ft_ls_print_error(flag) : 0;
	return (ops);
}

t_ops	ft_ls_recup_flags(char **flag)
{
	t_ops ops;

	ops = ft_ls_init_ops_struct();
	while (flag[ops.i] && flag[ops.i][0] == '-' && ft_strlen(flag[ops.i]) > 1)
	{
		ops.j = 0;
		if (ft_strcmp(flag[ops.i], "--") == 0)
		{
			ops.i++;
			break ;
		}
		while (flag[ops.i][ops.j++])
			ops = ft_ls_flag(flag[ops.i][ops.j], ops);
		ops.i++;
	}
	return (ops);
}

int		main(int ac, char **av)
{
	int		nb_arg;
	int		error;
	t_ops	ops;

	error = 0;
	ops = ft_ls_recup_flags(av);
	nb_arg = (ac - ops.i);
	if (nb_arg >= 2 && ops.f == 0)
		ft_sort_arg(nb_arg, av + ops.i, ops);
	ft_ls_check_dir(av + ops.i);
	ft_ls_check_if_file(av + ops.i, ops, nb_arg);
	if (nb_arg == 0)
		ft_ls(".", ops, nb_arg);
	else
		while (av[ops.i])
			if (ft_ls(av[ops.i++], ops, nb_arg) == 1)
				error = 1;
	return (error);
}
