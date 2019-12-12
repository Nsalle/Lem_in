/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 17:17:28 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 18:57:34 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static long long unsigned int	ft_is_negative(long long int nb, int *negativ)
{
	long long unsigned ret;

	ret = 0;
	if (nb < 0)
	{
		ret = nb * -1;
		if (g_save.type == 'd' || g_save.type == 'i')
			*negativ = 1;
	}
	else
		ret = nb;
	return (ret);
}

static size_t					ft_len(long long unsigned nb, size_t len,
		int base)
{
	while (nb != 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

static char						ft_base(int find_index, char mini_maj)
{
	char	ret;
	char	*base[2];

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	ret = '\0';
	while (find_index > 15)
		find_index -= 15;
	if (mini_maj == 'x' || mini_maj == 'o' || mini_maj == 'd' ||
			mini_maj == 'i' || mini_maj == 'b' || mini_maj == 'p')
		ret = base[0][find_index];
	else if (mini_maj == 'X')
		ret = base[1][find_index];
	return (ret);
}

static char						*ft_fucknorme(size_t len, int base, int neg,
		long long unsigned nb)
{
	char	*str;

	if (g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'p')
		base = 16;
	else if (g_save.type == 'o')
		base = 8;
	else if (g_save.type == 'i' || g_save.type == 'd')
		base = 10;
	else if (g_save.type == 'b')
		base = 2;
	len = ft_len(nb, len, base);
	if (!(str = ft_strnew(len + neg)))
		return (NULL);
	while (len--)
	{
		str[len + neg] = ft_base(nb % base, g_save.type);
		nb = nb / base;
	}
	(neg == 1) ? str[0] = '-' : 0;
	return (str);
}

char							*ft_itoa_base_pf(long long int n)
{
	int					negativ;
	long long unsigned	nb;

	negativ = 0;
	if (n == 0 || (n > UINT_MAX && g_save.l == 0 && g_save.ll == 0))
		return (ft_strdup("0"));
	else if (n == LONG_MIN)
	{
		nb = n * -1;
		if (g_save.type == 'd' || g_save.type == 'i')
			negativ = 1;
	}
	else if (g_save.h == 1 && n == 32768)
		nb = ft_is_negative(-32768, &negativ);
	else if (g_save.hh == 1 && n == 128 && g_save.type == 'd')
		nb = ft_is_negative(-128, &negativ);
	else if ((unsigned long)n == ULONG_MAX && g_save.l == 1)
		nb = ULONG_MAX;
	else if ((unsigned long long)n == ULLONG_MAX && g_save.ll == 1)
		nb = ULLONG_MAX;
	else if (g_save.type == 'd' || g_save.type == 'i')
		nb = ft_is_negative(n, &negativ);
	else
		nb = n;
	return (ft_fucknorme(0, 0, negativ, nb));
}
