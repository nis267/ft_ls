/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 17:49:25 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 17:03:42 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define PATH_MAX 4096
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include "libft/includes/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <errno.h>
# define MAGENTA "\033[35m"
# define BLUE "\033[1;49;36m"
# define RED "\033[31m"
# define GREEN "\033[7;49;32m"
# define END "\033[0m"

typedef struct stat			t_stat;
typedef struct passwd		t_passwd;
typedef struct group		t_group;
typedef struct dirent		t_dirent;

typedef struct			s_space
{
	size_t				sname;
	size_t				sli;
	size_t				ssize;
	size_t				susr;
	size_t				sgrp;
	size_t				sino;
	size_t				smajor;
	size_t				sminor;
	size_t				sblocks;
	size_t				tblocks;
}						t_space;

typedef struct			s_ls
{
	int					d_type;
	long				size;
	long				blocks;
	long				time;
	long				nlink;
	long				inode;
	unsigned int		major;
	unsigned int		minor;
	char				name[256];
	char				*user;
	char				*group;
	char				perm[12];
	char				path[PATH_MAX];
	struct s_ls			*next;
}						t_ls;

typedef struct			s_ops
{
	int					i;
	int					j;
	int					ur;
	int					l;
	int					r;
	int					t;
	int					a;
	int					ug;
	int					g;
	int					in;
	int					f;
	int					ua;
	int					s;
	int					o;
	int					tblocks;
	int					node_nb;
	int					file_arg;
	char				er;
	char				file[256];
	char				path[PATH_MAX];
	t_space				sp;
	t_dirent			*rep;
}						t_ops;

int						ft_ls(char *path, t_ops ops, int nb_arg);
void					ft_sort_arg(int arg, char **av, t_ops ops);
int						ft_ls_data_manipulation(DIR *dir, t_ops ops,
						char *path);
void					ft_full_path(t_ls *ls, char *d_name, char *path);
void					ft_ls_perm(mode_t st_mode, t_ls *ls);
void					ft_ls_display(t_ls *ls, t_ops ops, t_space s,
						char *path);
void					ft_ls_print_error(char er);
t_ops					ft_ls_flag(char flag, t_ops ops);
t_ops					ft_ls_recup_flags(char **flag);
void					ft_ls_check_dir(char **arg);
t_ops					ft_ls_init_ops_struct(void);
t_space					ft_ls_init_space_struct(void);
t_ls					*ft_ls_init_ls_struct(t_ls *ls);
void					ft_sort_list(t_ls **begin, int size, int o, int t_flag);
void					ft_ls_display_major_minor(int min, int maj,
						size_t smin, size_t smaj);
void					ft_ls_display_symbolic_link(char *path);
int						ft_ls_display_tblocks(char *name, t_ops ops);
void					ft_ls_color(char *name, int d_type, char *perm);
void					ft_ls_display_param(char *param, size_t param_max,
						int mode);
void					ls_display_time(long m_time);
void					ft_ls_print_error(char er);
t_space					ft_space(t_space s, t_ls *to_add, t_dirent *rep,
						t_ops ops);
void					ft_file_name_if_file(char *path, char *file);
void					ft_path_name_if_file(char *path);
void					ft_ls_recursive(t_ls *subdir, char *path, t_ops ops,
						int node_nb);
t_ls					*ft_ls_free_node(t_ls *ls);
void					ft_ls_check_dir(char **arg);
void					ft_ls_check_if_file(char **arg, t_ops ops, int nb_arg);
void					ft_ls_display_perm(char *perm);

#endif
