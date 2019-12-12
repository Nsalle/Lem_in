/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 10:43:30 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:31:12 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void		save_signe(void)
{
	int	i;

	i = 0;
	if (g_save.type == 'd' || g_save.type == 'i')
	{
		if (g_road.argument[0] == '-')
			g_save.signe = '-';
		else if ((g_road.argument[0] >= '0' && g_road.argument[0] <= '9') ||
				g_road.argument[0] == '+')
			g_save.signe = '+';
	}
}

int			copie_argv(char *tmp)
{
	if (g_road.argument == NULL)
	{
		if (!(g_road.argument = ft_strdup(g_road.tmp)))
			return (-1);
	}
	else if (g_road.tmp != NULL && g_road.argument != NULL)
	{
		if (!(tmp = ft_strdup(g_road.argument)))
			return (-1);
		ft_strdel(&g_road.argument);
		if (g_option.moins == 0 || (g_option.moins == 1 &&
					(g_road.tmp[0] == '-')))
		{
			if (!(g_road.argument = ft_strjoin(g_road.tmp, tmp)))
				return (-1);
		}
		else if (g_option.moins == 1 && g_road.tmp[0] != '-')
		{
			if (!(g_road.argument = ft_strjoin(tmp, g_road.tmp)))
				return (-1);
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&g_road.tmp);
	return (0);
}

static int	norme(char *tmp)
{
	save_signe();
	if (g_save.type == '%' || g_save.type == 'd' || g_save.type == 'i' ||
			g_save.type == 'c' || g_save.type == 's')
	{
		if (resolv_di() == -1)
			return (-1);
		if (copie_argv(tmp) == -1)
			return (-1);
	}
	else if (g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'o' ||
			g_save.type == 'u' || g_save.type == 'p' || g_save.type == 'b')
	{
		if (resolv_x() == -1)
			return (-1);
	}
	else if (g_save.type == 'f')
	{
		if (resolv_f() == -1)
			return (-1);
	}
	display(g_road.argument, g_save.type);
	return (0);
}

static void	norme2(int *j, char *format)
{
	if (format[*j] == '%' && format[*j + 1] == '%')
	{
		write(1, &format[*j], 1);
		g_road.nbchar += 1;
		*j += 2;
	}
	else if (format[*j] == '%' && format[*j + 1] == '\0')
		*j += 1;
	else
	{
		write(1, &format[*j], 1);
		g_road.nbchar += 1;
		*j += 1;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	int		j;

	j = 0;
	g_road.nbchar = 0;
	ini_strct(1, 1, 1);
	va_start(args, format);
	while (format[j] != '\0')
		if (format[j] == '%' && format[j + 1] != '%' && format[j + 1] != '\0')
		{
			analyse(&*(char*)(format + j));
			j = j + g_road.index;
			treatment(&args);
			if (norme(NULL) == -1)
			{
				ft_strdel(&g_road.argument);
				ft_strdel(&g_road.tmp);
				return (-1);
			}
		}
		else
			norme2(&j, (char*)format);
	va_end(args);
	return (g_road.nbchar);
}
