/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   analyse.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 17:13:03 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:31:43 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		analyse_option(char *format)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '+' || format[i] == '0' ||
			format[i] == ' ' || format[i] == '#')
	{
		if (format[i] == '-')
			g_option.moins = 1;
		if (format[i] == '+')
			g_option.plus = 1;
		if (format[i] == '0')
			g_option.zero = 1;
		if (format[i] == ' ')
			g_option.space = 1;
		if (format[i] == '#')
			g_option.diese = 1;
		i++;
	}
	return (i);
}

int		analyse_large(char *format)
{
	int	i;

	i = 0;
	g_save.large = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		g_save.precision = 0;
		g_save.precision = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

int		analyse_size(char *format)
{
	int	i;

	i = 0;
	if (format[i] == 'h' && format[i + 1] == 'h')
		g_save.hh = 1;
	else if (format[i] == 'h')
		g_save.h = 1;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		g_save.ll = 1;
	else if (format[i] == 'l')
		g_save.l = 1;
	else if (format[i] == 'L')
		g_save.grand_l = 1;
	if (g_save.hh == 1 || g_save.ll == 1)
		i += 2;
	else if (g_save.h == 1 || g_save.l == 1 || g_save.grand_l == 1)
		i++;
	return (i);
}

void	analyse(char *address_percent)
{
	int		index;

	ini_strct(1, 1, 1);
	index = 1;
	index += analyse_option(&*(address_percent + index));
	index += analyse_large(&*(address_percent + index));
	index += analyse_size(&*(address_percent + index));
	if (address_percent[index] == 'c' || address_percent[index] == 's' ||
			address_percent[index] == 'p' || address_percent[index] == 'd' ||
			address_percent[index] == 'i' || address_percent[index] == 'o' ||
			address_percent[index] == 'u' || address_percent[index] == 'x' ||
			address_percent[index] == 'X' || address_percent[index] == 'f' ||
			address_percent[index] == '%' || address_percent[index] == 'b')
	{
		g_save.type = address_percent[index];
		index++;
	}
	g_road.index = index;
}
