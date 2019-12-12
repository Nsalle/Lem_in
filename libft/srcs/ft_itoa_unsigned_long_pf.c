/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_unsigned_long_pf.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 20:35:53 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:05:09 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_len(unsigned long long int nb, int len)
{
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char			*ft_itoa_unsigned_long_pf(unsigned long long int n)
{
	char					*str;
	size_t					len;
	unsigned long long int	nb;

	if (n == 0 || (n > UINT_MAX && g_save.l == 0 && g_save.ll == 0))
		return (ft_strdup("0"));
	else
		nb = n;
	len = 0;
	len = ft_len(nb, len);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
