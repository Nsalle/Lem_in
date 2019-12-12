/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_resolv_x.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 09:13:01 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:28:21 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	regroup1(char *tmp, char *tmp2, char *large)
{
	if (!(tmp = ft_strjoin(g_road.tmp, large)))
		return (-1);
	ft_strdel(&g_road.tmp);
	if (!(tmp2 = ft_strjoin(tmp, g_road.argument)))
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&g_road.argument);
	if (!(g_road.argument = ft_strdup(tmp2)))
		return (-1);
	ft_strdel(&tmp2);
	return (0);
}

int	regroup2(char *tmp, char *tmp2, char *large)
{
	if (g_option.moins == 1)
	{
		if (!(tmp = ft_strjoin(g_road.argument, large)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strjoin(g_road.tmp, tmp)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(large, g_road.tmp)))
			return (-1);
		if (!(tmp2 = ft_strjoin(tmp, g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp2)))
			return (-1);
	}
	ft_strdel(&g_road.tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (0);
}

int	regroup3(char *tmp)
{
	if (!(tmp = ft_strjoin(g_road.tmp, g_road.argument)))
		return (-1);
	ft_strdel(&g_road.argument);
	ft_strdel(&g_road.tmp);
	if (!(g_road.argument = ft_strdup(tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

int	regroup4(char *tmp, char *large)
{
	if ((g_option.moins == 0 && ft_strchr(large, ' ') != NULL) ||
		(ft_strchr(large, '0') != NULL && g_option.moins == 0) ||
		(g_option.moins == 1 && ft_strchr(large, '0') != NULL))
	{
		if (!(tmp = ft_strjoin(large, g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(g_road.argument, large)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
	}
	ft_strdel(&g_road.tmp);
	ft_strdel(&tmp);
	return (0);
}

int	utils_resolv_x(char *tmp, char *tmp2, char **large)
{
	if (g_road.tmp != NULL && large != NULL)
	{
		if ((ft_strchr(*large, '0') != NULL && g_option.moins == 0 &&
			g_road.tmp != NULL) || (g_option.moins == 1 &&
			ft_strchr(*large, '0') != NULL && g_road.tmp != NULL))
		{
			if (regroup1(tmp, tmp2, *large) == -1)
				return (-1);
		}
		else if (ft_strchr(*large, ' ') != NULL)
		{
			if (regroup2(tmp, tmp2, *large) == -1)
				return (-1);
		}
		else if (ft_strchr(*large, ' ') == NULL &&
				ft_strchr(*large, '0') == NULL)
			if (regroup3(tmp) == -1)
				return (-1);
	}
	else if (*large != NULL)
		if (regroup4(tmp, *large) == -1)
			return (-1);
	return (0);
}
