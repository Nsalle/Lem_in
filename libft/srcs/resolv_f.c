/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv_f.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 16:16:49 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:26:26 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	skipmoin_f(char *tmp, int i)
{
	if (!(g_road.signe = ft_strnew(1)))
		return (-1);
	if (g_road.argument != NULL)
	{
		if (g_road.argument[0] == '-')
			g_road.signe[0] = '-';
		else if (g_road.argument[0] != '-')
			g_road.signe[0] = '+';
		if (g_road.argument[0] == '+' || g_road.argument[0] == '-')
		{
			while (g_road.argument[++i] != '\0')
				g_road.argument[i] = g_road.argument[i + 1];
			g_road.argument[i] = '\0';
			if (!(tmp = ft_strdup(g_road.argument)))
				return (-1);
			ft_strdel(&g_road.argument);
			if (!(g_road.argument = ft_strdup(tmp)))
				return (-1);
			ft_strdel(&tmp);
		}
	}
	return (0);
}

int			size_f(char *tmp, char *diese, int i[2], int presence_signe)
{
	if (g_save.large > 0)
		if (!(tmp = ft_strnew(g_save.large)))
			return (-1);
	if (g_option.diese == 1 && g_save.precision == 0)
		if (!(diese = ft_strdup(".")))
			return (-1);
	i[1] += (g_road.argument != NULL) ? (int)ft_strlen(g_road.argument) : 0;
	i[1] += (g_road.tmp != NULL) ? (int)ft_strlen(g_road.argument) : 0;
	i[1] += (diese != NULL) ? (int)ft_strlen(diese) : 0;
	while (g_save.large > (++i[0] + i[1] + presence_signe))
		tmp[i[0]] = (g_option.zero == 0) ? ' ' : '0';
	if (tmp != NULL && !(g_road.large = ft_strdup(tmp)))
		return (-1);
	ft_strdel(&tmp);
	if (diese != NULL)
	{
		if (!(tmp = ft_strjoin(g_road.argument, diese)))
			return (-1);
		ft_strdel(&g_road.argument);
		ft_strdel(&diese);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int			space_plus_f(void)
{
	if (g_road.signe[0] == '+' && g_option.space == 1 && g_option.plus == 0 &&
		g_road.argument != NULL && g_save.large >
		(int)ft_strlen(g_road.argument))
	{
		if (!(g_road.tmp = ft_strdup(" ")))
			return (-1);
	}
	return (0);
}

int			regroup(char *tmp)
{
	if (g_road.argument != NULL && g_road.large != NULL && g_option.zero == 1)
	{
		if (resolv_norme_f3(NULL) == -1)
			return (-1);
	}
	if (g_road.signe[0] == '-' || (g_road.signe[0] != '-' &&
				g_option.plus == 1))
	{
		if (!(tmp = ft_strjoin(g_road.signe, g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		ft_strdel(&g_road.signe);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	if (g_option.moins == 1 && g_road.large != NULL)
	{
		if (resolv_norme_f(NULL) == -1)
			return (-1);
	}
	else if (g_option.moins == 0 && g_road.large != NULL)
		if (resolv_norme_f2(NULL) == -1)
			return (-1);
	return (0);
}

int			resolv_f(void)
{
	int	i[2];

	i[0] = -1;
	i[1] = 0;
	if (skipmoin_f(NULL, -1) == -1)
		return (-1);
	if (space_plus_f() == -1)
		return (-1);
	if (size_f(NULL, NULL, i, (g_road.signe != '\0') ? 1 : 0) == -1)
		return (-1);
	if (regroup(NULL) == -1)
		return (-1);
	return (0);
}
