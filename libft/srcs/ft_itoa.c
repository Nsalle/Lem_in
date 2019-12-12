/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:38:01 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:03:56 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_is_negative(int *nb, int *negativ)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		*negativ = 1;
	}
}

static size_t	ft_len(int nb, int len)
{
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		negativ;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	nb = n;
	len = 0;
	len = ft_len(nb, len);
	negativ = 0;
	ft_is_negative(&n, &negativ);
	if (!(str = ft_strnew(len + negativ)))
		return (NULL);
	while (len--)
	{
		str[len + negativ] = '0' + (n % 10);
		n = n / 10;
	}
	if (negativ == 1)
		str[0] = '-';
	return (str);
}
