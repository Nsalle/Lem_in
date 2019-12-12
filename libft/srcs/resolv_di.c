/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolv_di.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 22:49:30 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:26:08 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		resolv_di_precision(char *tmp, int i)
{
	char	*tmp2;

	if (g_save.precision != -1 && g_save.precision > 0 &&
			(g_save.type == 'd' || g_save.type == 'i'))
	{
		if (!(tmp = ft_strnew(g_save.precision)))
			return (-1);
		while (((++i + (int)ft_strlen(g_road.argument)) < g_save.precision))
			tmp[i] = '0';
		if (i != -1)
			tmp[i] = '\0';
		if (!(tmp2 = ft_strjoin(tmp, g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (!(g_road.argument = ft_strdup(tmp2)))
			return (-1);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (g_save.precision < (int)ft_strlen(g_road.argument) &&
			g_save.precision >= 0 && g_save.type != '%' && g_save.type != 'i' &&
			g_save.type != 'd')
		g_road.argument[g_save.precision] = '\0';
	return (0);
}

int		resolv_di_moins(int moins)
{
	char	*tmp;

	tmp = NULL;
	if (moins == 1 || g_save.signe == '-')
	{
		if (place_moins(tmp) == -1)
			return (-1);
	}
	return (0);
}

int		resolv_di_size(char *tmp, int size, char *b, int moins)
{
	int	j;
	int	i;
	int	signe;

	j = 0;
	i = -1;
	signe = 0;
	if (ft_strlen(b) > 0)
		signe = 1;
	if (ft_strlen(g_road.argument) == 0 &&
		ft_strchr(g_road.argument, '\0') != NULL && g_save.type == 'c')
		j = 1;
	if (!(tmp = ft_strnew(g_save.large)))
		return (-1);
	if (g_option.zero == 1 && (g_save.precision == -1 || g_save.precision == 0))
		while ((size + ++i + j + signe + moins) < g_save.large)
			tmp[i] = '0';
	else
		while ((size + ++i + j + signe + moins) < g_save.large)
			tmp[i] = ' ';
	tmp[i] = '\0';
	if (swap(&tmp) == -1)
		return (-1);
	return (0);
}

int		resolv_di_plus(char **str)
{
	if (g_option.plus == 1)
	{
		if (!(*str = ft_strdup("+")))
			return (-1);
	}
	else if (g_option.space == 1)
	{
		if (!(*str = ft_strdup(" ")))
			return (-1);
	}
	return (0);
}

int		resolv_di(void)
{
	int		moins;
	char	*space_plus;

	moins = 0;
	space_plus = NULL;
	if (norme_di(NULL, &moins, -1, &space_plus) == -1)
		return (-1);
	if (norme_di2(ft_strlen(g_road.argument), NULL, &space_plus, moins) == -1)
		return (-1);
	if ((g_save.type == 'd' || g_save.type == 'i') &&
			(g_option.plus == 1 || g_option.space == 1))
	{
		if (norme_di3(&space_plus, NULL) == -1)
			return (-1);
		else if (space_plus != NULL)
			if (norme_di4(&space_plus) == -1)
				return (-1);
	}
	if (resolv_di_moins(moins) == -1)
		return (-1);
	return (0);
}
