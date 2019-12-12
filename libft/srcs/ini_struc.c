/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ini_struc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 15:22:59 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:42:42 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ini_road(void)
{
	g_road.index = 0;
	ft_strdel(&g_road.argument);
	ft_strdel(&g_road.tmp);
	ft_strdel(&g_road.signe);
	g_road.c2 = 0;
}

void	ini_option(void)
{
	g_option.moins = 0;
	g_option.plus = 0;
	g_option.zero = 0;
	g_option.space = 0;
	g_option.diese = 0;
}

void	ini_save(void)
{
	g_save.signe = '\0';
	g_save.type = '\0';
	g_save.l = 0;
	g_save.ll = 0;
	g_save.h = 0;
	g_save.hh = 0;
	g_save.grand_l = 0;
	g_save.large = -1;
	g_save.precision = -1;
}

void	ini_strct(int a, int b, int c)
{
	if (a == 1)
		ini_road();
	if (b == 1)
		ini_option();
	if (c == 1)
		ini_save();
}
