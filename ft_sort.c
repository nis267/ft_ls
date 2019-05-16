/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:09:49 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:11:42 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_reverse_list(t_ls **elem, int size)
{
	t_ls	*tmp;
	int		min;

	min = 0;
	size = size - 1;
	while (min < size)
	{
		tmp = elem[min];
		elem[min] = elem[size];
		elem[size] = tmp;
		min++;
		size--;
	}
	return (elem);
}

t_ls	**ft_sort_list_next(t_ls **elem, int size, int t_flag)
{
	int		i;
	int		j;
	t_ls	*actual;

	actual = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (t_flag == 1 && (elem[i]->time != elem[j]->time) ?
				elem[i]->time > elem[j]->time :
				ft_strcmp(elem[i]->name, elem[j]->name) < 0)
			{
				actual = elem[i];
				elem[i] = elem[j];
				elem[j] = actual;
			}
			j++;
		}
		i++;
	}
	return (elem);
}

void	ft_sort_list(t_ls **begin, int size, int o, int t_flag)
{
	t_ls	*elem[size];
	t_ls	*actual;
	int		i;

	actual = *begin;
	i = 0;
	while (actual)
	{
		elem[i++] = actual;
		actual = actual->next;
	}
	ft_sort_list_next(elem, size, t_flag);
	if (o)
		ft_reverse_list(elem, size);
	actual = elem[0];
	i = 0;
	while (i < size)
	{
		actual->next = elem[i];
		actual = actual->next;
		i++;
	}
	actual->next = NULL;
	*begin = elem[0];
}

void	ft_sort_arg(int arg, char **av, t_ops ops)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < arg)
	{
		j = 0;
		while (j < arg)
		{
			if (ft_strcmp(av[ops.r ? j : i], av[ops.r ? i : j]) < 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
