/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   treatment.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 17:13:37 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:27:43 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	treatment_option(void)
{
	if (g_save.type == 'd' && g_option.diese == 1)
		g_option.diese = 0;
	if (g_save.type == 'i' || g_save.type == 'u' || g_save.type == 'x' ||
		g_save.type == 'X' || g_save.type == 'o' || g_save.type == 'd')
	{
		if (g_save.precision >= 0 || (g_option.moins == 1 &&
				g_option.zero == 1))
			g_option.zero = 0;
	}
	if (ft_strlen(g_road.argument) == 1 && ft_strchr(g_road.argument, '0')
			!= NULL && (g_save.type == 'x' || g_save.type == 'X' ||
			g_save.type == 'o' || g_save.type == 'u' || g_save.type == 's' ||
			g_save.type == 'p'))
	{
		if (g_save.type != 'o')
			g_option.diese = 0;
		if (g_save.precision == 0)
			g_road.argument[0] = '\0';
		if (g_save.type == 'o' && g_option.diese == 1)
			g_road.argument[0] = '\0';
	}
}

void	treatment_type_norme(char c, va_list *args)
{
	if ((g_save.type == 'd' || g_save.type == 'i') && (g_save.l == 1 ||
		g_save.ll == 1))
		g_road.argument = ft_itoa_pf(va_arg(*args, long long));
	else if ((g_save.type == 'd' || g_save.type == 'i') && g_save.h == 0 &&
			g_save.hh == 0)
		g_road.argument = ft_itoa_base_pf(va_arg(*args, int));
	else if ((g_save.type == 'd' || g_save.type == 'i') && (g_save.h == 1))
		g_road.argument = ft_itoa_base_pf((short int)va_arg(*args, int));
	else if ((g_save.type == 'd' || g_save.type == 'i') && (g_save.hh == 1))
		g_road.argument = ft_itoa_base_pf((char)va_arg(*args, int));
	else if (g_save.type == 's')
		g_road.argument = ft_strdup(va_arg(*args, char*));
	else if (g_save.type == 'c')
	{
		c = (char)va_arg(*args, int);
		if (c == 0)
			g_road.c2 = 1;
		if (!(g_road.argument = (char*)malloc(sizeof(char) * 2)))
			;
		g_road.argument[1] = '\0';
		g_road.argument[0] = c;
	}
}

void	norme_treatment(va_list *args)
{
	if (g_save.type == 'f' && g_save.grand_l == 1)
		g_road.argument = ft_itoa_long_double_pf((long double)va_arg(*args,
					long double));
	else if (g_save.type == 'f')
		g_road.argument = ft_itoa_long_double_pf((long double)va_arg(*args,
					double));
}

void	treatment_type(va_list *args)
{
	if ((g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'o' ||
			g_save.type == 'b') && (g_save.ll == 1))
		g_road.argument = ft_itoa_base_unsigned_long_pf(va_arg(*args,
					long long unsigned));
	else if ((g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'o' ||
				g_save.type == 'b') && (g_save.h == 0 && g_save.hh == 0))
		g_road.argument = ft_itoa_base_pf(va_arg(*args, long long));
	else if ((g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'o' ||
				g_save.type == 'b') && g_save.h == 1)
		g_road.argument = ft_itoa_base_pf((unsigned short)va_arg(*args, int));
	else if ((g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'o' ||
				g_save.type == 'b') && g_save.hh == 1)
		g_road.argument = ft_itoa_base_pf((unsigned char)va_arg(*args, int));
	else if (g_save.type == 'u' && g_save.h == 0 && g_save.hh == 0)
		g_road.argument = ft_itoa_unsigned_long_pf(va_arg(*args,
					unsigned long long));
	else if (g_save.type == 'u' && g_save.h == 1)
		g_road.argument = ft_itoa_unsigned_pf((unsigned short)va_arg(*args,
					unsigned));
	else if (g_save.type == 'u' && g_save.hh == 1)
		g_road.argument = ft_itoa_unsigned_pf((unsigned char)va_arg(*args,
					unsigned));
	else
		norme_treatment(args);
}

int		treatment(va_list *args)
{
	if (g_save.type == '%')
		g_road.argument = ft_strdup("%");
	else if (g_save.type == 'p')
		g_road.argument = ft_itoa_base_unsigned_long_pf(va_arg(*args,
					unsigned long));
	else
		treatment_type_norme('\0', args);
	treatment_type(args);
	treatment_option();
	return (0);
}
