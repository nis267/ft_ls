/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_error.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 16:35:27 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 15:33:46 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_print_error(char er)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(er);
	ft_putchar('\n');
	ft_putendl("usage: ls [-AGRafgiliorst] [file ...]");
	exit(1);
}
