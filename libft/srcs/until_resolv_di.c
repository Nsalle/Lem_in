/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   until_resolv_di.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 04:56:12 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:28:03 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		swap(char **tmp)
{
	char	*tmp2;

	tmp2 = NULL;
	if (g_road.tmp != NULL)
	{
		if (!(tmp2 = ft_strdup(g_road.tmp)))
			return (-1);
		ft_strdel(&g_road.tmp);
	}
	if (tmp2 != NULL && tmp != NULL)
	{
		if (!(g_road.tmp = ft_strjoin(*tmp, tmp2)))
			return (-1);
		ft_strdel(&tmp2);
	}
	else if (!(g_road.tmp = ft_strdup(*tmp)))
		return (-1);
	ft_strdel(tmp);
	return (0);
}

int		place_moins(char *tmp)
{
	if (g_road.tmp == NULL || g_road.tmp[0] == ' ' ||
			ft_strlen(g_road.tmp) == 0)
	{
		if (!(tmp = ft_strjoin("-", g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	else if (g_road.tmp[0] == '0')
	{
		if (!(tmp = ft_strjoin("-", g_road.tmp)))
			return (-1);
		ft_strdel(&g_road.tmp);
		if (!(g_road.tmp = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int		resolv_s_large(int i, char *tmp, int size)
{
	if (!(tmp = ft_strnew(g_save.large)))
		return (-1);
	if (g_save.precision < size && g_save.precision > -1)
		size = g_save.precision;
	else
		size = ft_strlen(g_road.argument);
	if (g_option.zero == 1 && size < g_save.large)
		while (g_save.large > (++i + size))
			tmp[i] = '0';
	else if (size < g_save.large && g_save.precision <= 0)
		while ((size + ++i) < g_save.large)
			tmp[i] = ' ';
	else if ((size < g_save.large && g_save.precision > 0 && g_save.precision
			>= g_save.large) || (size < g_save.large && g_save.precision > 0 &&
			g_save.precision < g_save.large && g_save.precision != -1))
		while (g_save.large > (++i + size))
			tmp[i] = ' ';
	else
		i = 0;
	tmp[i] = '\0';
	if (swap(&tmp) == -1)
		return (-1);
	return (0);
}

int		skipmoin(char *tmp, int *moins)
{
	int	i;

	i = 0;
	tmp = NULL;
	if (g_road.argument != NULL)
	{
		if (g_road.argument[0] == '-')
		{
			*moins = 1;
			while (g_road.argument[i] != '\0')
			{
				g_road.argument[i] = g_road.argument[i + 1];
				i++;
			}
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
