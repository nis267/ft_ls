/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_recup_perm.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 00:36:13 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 16:51:03 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_get_acl(char *path)
{
	acl_t acl;

	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		acl_free(acl);
		return (1);
	}
	return (0);
}

int		ft_ls_get_extended_attributes(char *path)
{
	char liste[255];

	if ((listxattr(path, liste, 255, XATTR_NOFOLLOW)) > 0 && ft_strlen(liste))
		return (1);
	return (0);
}

void	ft_ls_perm(mode_t st_mode, t_ls *ls)
{
	ls->perm[0] = (st_mode & S_IFMT) == S_IFIFO ? 'p' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFCHR ? 'c' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFDIR ? 'd' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFBLK ? 'b' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFREG ? '-' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFLNK ? 'l' : ls->perm[0];
	ls->perm[0] = (st_mode & S_IFMT) == S_IFSOCK ? 's' : ls->perm[0];
	ls->perm[1] = st_mode & S_IRUSR ? 'r' : '-';
	ls->perm[2] = st_mode & S_IWUSR ? 'w' : '-';
	ls->perm[3] = st_mode & S_IXUSR ? 'x' : '-';
	ls->perm[3] = st_mode & S_ISUID && st_mode & S_IXUSR ? 's' : ls->perm[3];
	ls->perm[3] = st_mode & S_ISUID && ls->perm[3] == '-' ? 'S' : ls->perm[3];
	ls->perm[4] = st_mode & S_IRGRP ? 'r' : '-';
	ls->perm[5] = st_mode & S_IWGRP ? 'w' : '-';
	ls->perm[6] = st_mode & S_IXGRP ? 'x' : '-';
	ls->perm[6] = st_mode & S_ISGID && st_mode & S_IXGRP ? 's' : ls->perm[6];
	ls->perm[6] = st_mode & S_ISGID && ls->perm[6] == '-' ? 'S' : ls->perm[6];
	ls->perm[7] = st_mode & S_IROTH ? 'r' : '-';
	ls->perm[8] = st_mode & S_IWOTH ? 'w' : '-';
	ls->perm[9] = st_mode & S_IXOTH ? 'x' : '-';
	ls->perm[9] = st_mode & S_ISVTX && st_mode & S_IXOTH ? 't' : ls->perm[9];
	ls->perm[9] = st_mode & S_ISVTX && ls->perm[9] == '-' ? 'T' : ls->perm[9];
	ls->perm[10] = ft_ls_get_acl(ls->path) == 1 ? '+' : '\0';
	ls->perm[10] = ft_ls_get_extended_attributes(ls->path) ? '@' : ls->perm[10];
	ls->perm[11] = '\0';
}
