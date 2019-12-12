/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 10:38:59 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 18:57:49 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	display(char *str, char a)
{
	a = '0';
	if (g_road.c2 == 1 && g_save.type == 'c')
	{
		if (g_option.moins == 0)
		{
			write(1, str, ft_strlen(str));
			write(1, "\0", 1);
		}
		else
		{
			write(1, "\0", 1);
			write(1, str, ft_strlen(str));
		}
		g_road.nbchar += (1 + ft_strlen(str));
	}
	else
	{
		write(1, str, ft_strlen(str));
		g_road.nbchar = g_road.nbchar + ft_strlen(str);
	}
	ft_strdel(&g_road.argument);
}
