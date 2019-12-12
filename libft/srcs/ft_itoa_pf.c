/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_pf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 09:47:17 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:04:51 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_is_negative(long long int *nb, int *negativ)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		*negativ = 1;
	}
}

static size_t	ft_len(long long int nb, int len)
{
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void		ft_norme(size_t len, char **str, int negativ, long long int n)
{
	while (len--)
	{
		str[0][len + negativ] = '0' + (n % 10);
		n = n / 10;
	}
}

char			*ft_itoa_pf(long long int n)
{
	char			*str;
	size_t			len;
	int				negativ;
	long long int	nb;

	if (n == LONG_MIN && (g_save.l == 1 || g_save.ll == 1))
		return (ft_strdup("-9223372036854775808"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == 0 || n == -0)
		return (ft_strdup("0"));
	else
		nb = n;
	len = ft_len(nb, 0);
	negativ = 0;
	ft_is_negative(&n, &negativ);
	if (!(str = ft_strnew(len + negativ)))
		return (NULL);
	ft_norme(len, &str, negativ, n);
	len = 0;
	str[ft_len(nb, len) + negativ] = '\0';
	(negativ == 1) ? str[0] = '-' : 0;
	return (str);
}
