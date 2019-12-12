/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv_norme_f.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 11:27:32 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:27:02 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	resolv_norme_f(char *tmp)
{
	if (!(tmp = ft_strjoin(g_road.argument, g_road.large)))
		return (-1);
	ft_strdel(&g_road.argument);
	ft_strdel(&g_road.large);
	if (g_road.tmp != NULL && ft_strchr(g_road.tmp, ' ') != NULL)
	{
		if (!(g_road.argument = ft_strjoin(g_road.tmp, tmp)))
			return (-1);
	}
	else
	{
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
	}
	ft_strdel(&g_road.tmp);
	ft_strdel(&tmp);
	return (0);
}

int	resolv_norme_f2(char *tmp)
{
	if (!(tmp = ft_strjoin(g_road.large, g_road.argument)))
		return (-1);
	ft_strdel(&g_road.argument);
	ft_strdel(&g_road.large);
	if (g_road.tmp != NULL && ft_strchr(g_road.tmp, ' ') != NULL)
	{
		if (!(g_road.argument = ft_strjoin(tmp, g_road.tmp)))
			return (-1);
	}
	else
	{
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
	}
	ft_strdel(&g_road.tmp);
	ft_strdel(&tmp);
	return (0);
}

int	resolv_norme_f3(char *tmp)
{
	if (!(tmp = ft_strjoin(g_road.argument, g_road.large)))
		return (-1);
	ft_strdel(&g_road.argument);
	ft_strdel(&g_road.large);
	if (!(g_road.argument = ft_strdup(tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}
