/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_part_3.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 17:22:58 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:01:27 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_color(char *name, int d_type, char *perm)
{
	if (d_type == 4 && perm[8] == 'w' && (perm[9] == 't' || perm[9] == 'T'))
		ft_putstr(GREEN);
	else if (d_type == 4)
		ft_putstr(BLUE);
	else if (d_type == 10)
		ft_putstr(MAGENTA);
	else if (d_type == 8 && perm[9] == 'x')
		ft_putstr(RED);
	else if (d_type == 8 && perm[9] == 'x')
		ft_putstr(RED);
	else
		return (ft_putstr(name));
	ft_putstr(name);
	ft_putstr(END);
}

void	ls_display_time(long m_time)
{
	int i;
	int j;

	i = 4;
	if (m_time <= (time(NULL) - 15778800))
	{
		j = 10;
		while (i < j)
			ft_putchar(ctime(&m_time)[i++]);
		ft_putstr("  ");
		i = 20;
		j = 24;
	}
	else
	{
		i = 4;
		j = 16;
	}
	while (i < j)
		ft_putchar(ctime(&m_time)[i++]);
	ft_putchar(' ');
}

void	ft_ls_display_param(char *param, size_t param_max, int mode)
{
	unsigned long i;

	i = 0;
	if (mode == 1 || mode == 2)
		ft_putstr(param);
	while (i < (param_max - ft_strlen(param)) && mode != 2)
	{
		ft_putchar(' ');
		i++;
	}
	if (mode == 1)
		ft_putstr("  ");
	else
	{
		if (!mode)
		{
			ft_putstr(param);
			ft_putchar(' ');
		}
	}
	if (param)
		free(param);
}
