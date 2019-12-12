/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv_x.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 22:06:24 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:27:25 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	resolv_x_diese(void)
{
	if (g_option.diese == 1 && g_save.type == 'o')
	{
		if (!(g_road.tmp = ft_strdup("0")))
			return (-1);
	}
	else if ((g_option.diese == 1 && g_save.type == 'x') ||
			(g_save.type == 'p' && g_option.diese == 0))
	{
		if (!(g_road.tmp = ft_strdup("0x")))
			return (-1);
	}
	else if (g_option.diese == 1 && g_save.type == 'X')
	{
		if (!(g_road.tmp = ft_strdup("0X")))
			return (-1);
	}
	return (0);
}

int	resolv_norme_x(char **tmp, char **tmp2, int i, int j)
{
	if (g_road.tmp != NULL)
	{
		if (!(tmp[0] = ft_strdup(g_road.tmp)))
			return (-1);
		ft_strdel(&g_road.tmp);
	}
	if ((g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'p')
			&& g_option.diese == 1)
		i = 0;
	else if (g_save.type == 'o' && g_option.diese == 1)
		i = 1;
	if (g_save.precision > 0)
	{
		if (!(tmp2[0] = ft_strnew(g_save.precision)))
			return (-1);
		while (((int)ft_strlen(g_road.argument) + i + j) < g_save.precision)
		{
			tmp2[0][j] = '0';
			j++;
		}
	}
	return (0);
}

int	resolv_x_precision(char *tmp, char *tmp2)
{
	if (resolv_norme_x(&tmp, &tmp2, 0, 0) == -1)
		return (-1);
	if (tmp != NULL && tmp2 != NULL)
	{
		if (!(g_road.tmp = ft_strjoin(tmp, tmp2)))
			return (-1);
	}
	else if (tmp2 != NULL)
	{
		if (!(g_road.tmp = ft_strdup(tmp2)))
			return (-1);
	}
	else if (tmp != NULL)
		if (!(g_road.tmp = ft_strdup(tmp)))
			return (-1);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (0);
}

int	resolv_x_large(char **large)
{
	int	i;

	i = -1;
	if (g_save.large != -1 && g_save.large > 0)
	{
		if (!(*large = ft_strnew(g_save.large)))
			return (-1);
		if (g_option.zero == 0 || (g_option.moins == 1 && g_option.zero == 1))
		{
			while (((int)ft_strlen(g_road.argument) + ++i +
						(int)ft_strlen(g_road.tmp)) < g_save.large)
				large[0][i] = ' ';
		}
		else
		{
			while (((int)ft_strlen(g_road.argument) + ++i +
					(int)ft_strlen(g_road.tmp)) < g_save.large)
				large[0][i] = '0';
		}
		large[0][i] = '\0';
	}
	else
		return (-2);
	return (0);
}

int	resolv_x(void)
{
	char	*large;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	large = NULL;
	if (resolv_x_diese() == -1)
		return (-1);
	if ((int)ft_strlen(g_road.argument) < g_save.precision)
	{
		if (resolv_x_precision(tmp, tmp2) == -1)
			return (-1);
	}
	if (resolv_x_large(&large) == -1)
		return (-1);
	if (utils_resolv_x(tmp, tmp2, &large) == -1)
		return (-1);
	if (large != NULL)
		ft_strdel(&large);
	return (0);
}
