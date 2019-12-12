/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_long_unsigned.c                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 18:15:37 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:04:13 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_len(long long unsigned int nb, int len, int base)
{
	while (nb != 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

static char		ft_base(int find_index, char mini_maj)
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

static int		select_base(void)
{
	int	base;

	base = 0;
	if (g_save.type == 'x' || g_save.type == 'X' || g_save.type == 'p')
		base = 16;
	else if (g_save.type == 'o')
		base = 8;
	else if (g_save.type == 'i' || g_save.type == 'd')
		base = 10;
	else if (g_save.type == 'b')
		base = 2;
	return (base);
}

char			*ft_itoa_base_unsigned_long_pf(long long unsigned n)
{
	char				*str;
	size_t				len;
	long long unsigned	nb;
	int					base;

	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	else if (n == ULLONG_MAX)
		nb = ULLONG_MAX;
	nb = n;
	len = 0;
	base = select_base();
	len = ft_len(nb, len, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = ft_base(nb % base, g_save.type);
		nb = nb / base;
	}
	return (str);
}
