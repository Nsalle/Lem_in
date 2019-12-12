/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv_norme_di.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 07:48:40 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:26:42 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	norme_di(char *tmp, int *moins, int i, char **space_plus)
{
	if (g_road.argument == NULL)
	{
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup("(null)")))
			return (-1);
	}
	if (ft_strlen(g_road.argument) == 1 && g_road.argument[0] == '0' &&
			g_save.precision != -1)
	{
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup("")))
			return (-1);
	}
	if (g_save.signe == '+')
	{
		if (resolv_di_plus(space_plus) == -1)
			return (-1);
	}
	if (skipmoin(tmp, moins) == -1)
		return (-1);
	if (g_save.precision != -1)
		if (resolv_di_precision(tmp, i) == -1)
			return (-1);
	return (0);
}

int	norme_di2(size_t s, char *tmp, char **space_plus, int moins)
{
	s = ft_strlen(g_road.argument);
	if (g_road.tmp != NULL)
		s += ft_strlen(g_road.tmp);
	if ((g_save.large > (int)s && g_save.large > g_save.precision) &&
			(g_save.type == '%' || g_save.type == 'd' ||
			g_save.type == 'i' || g_save.type == 'c'))
	{
		if (resolv_di_size(tmp, s, *space_plus, moins) == -1)
			return (-1);
	}
	if (g_save.type == 's' && g_save.large != -1 && g_save.large > 0)
	{
		if (resolv_s_large(-1, tmp, s) == -1)
			return (-1);
	}
	ft_strdel(&tmp);
	return (0);
}

int	norme_di3(char **space_plus, char *tmp)
{
	if ((g_road.tmp != NULL && g_road.tmp[0] == ' ' && *space_plus != NULL) ||
			(g_road.tmp == NULL && *space_plus != NULL))
	{
		if (!(tmp = ft_strjoin(*space_plus, g_road.argument)))
			return (-1);
		ft_strdel(space_plus);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	else if ((g_road.tmp != NULL && g_road.tmp[0] == '0' &&
				*space_plus != NULL))
	{
		if (!(tmp = ft_strjoin(*space_plus, g_road.tmp)))
			return (-1);
		ft_strdel(space_plus);
		ft_strdel(&g_road.tmp);
		if (!(g_road.tmp = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int	norme_di4(char **space_plus)
{
	ft_strdel(&g_road.tmp);
	if (!(g_road.tmp = ft_strjoin(*space_plus, g_road.argument)))
		return (-1);
	ft_strdel(&g_road.argument);
	ft_strdel(space_plus);
	if (!(g_road.argument = ft_strdup(g_road.tmp)))
		return (-1);
	ft_strdel(&g_road.tmp);
	return (0);
}
