/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_long_double_pf.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 18:17:45 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:04:32 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_len(long double *nb)
{
	size_t	len;

	len = 0;
	while (*nb >= 1)
	{
		len++;
		*nb /= 10;
	}
	return (len);
}

static void		recup_entier(long double fl, size_t len, char **entier,
		int *index)
{
	int	i;

	i = *index;
	if (len == 0 && g_save.precision != 0)
	{
		entier[0][0] = '0';
		i++;
	}
	else
		while (len--)
		{
			fl *= 10;
			(*entier)[i] = '0' + ((unsigned int)fl);
			fl = fl - ((unsigned int)fl);
			i++;
		}
	*index = i;
}

static void		norme(int p, long double c, int i, long double *n)
{
	long double fl[2];

	if (p == 0)
	{
		fl[0] = *n;
		fl[1] = fl[0] / 10;
		fl[0] = fl[1] - (long long int)fl[1];
		fl[0] *= 10;
		(((int)fl[0] % 2) != 0 || (fl[0] - (int)fl[0]) > 0.5) ? *n += 1 : 0;
	}
	else if (p > 0)
	{
		fl[0] = *n;
		fl[0] -= (long long int)fl[0];
		i = -1;
		c = 1;
		while (++i < p)
		{
			fl[0] -= (long long int)fl[0];
			fl[0] *= 10;
			c /= 10;
		}
		(((int)fl[0] % 2 != 0 && (int)fl[0] != 10) ||
			(fl[0] - (int)fl[0] > 0.5)) ? *n += c : 0;
	}
}

static char		*norme2(int *i, long double fl, char **entier)
{
	int				j;
	char			*tmp1;
	unsigned int	tmp;

	j = 0;
	while (j < i[2])
	{
		fl = fl - ((unsigned int)fl);
		tmp = fl * 10;
		fl *= 10;
		entier[0][i[0] + 1 + j] = '0' + ((unsigned int)fl);
		j++;
	}
	if (i[1] == 1)
	{
		if (!(tmp1 = ft_strjoin("-", entier[0])))
			return (NULL);
		ft_strdel(entier);
		if (!(entier[0] = ft_strdup(tmp1)))
			return (NULL);
		ft_strdel(&tmp1);
	}
	return (entier[0]);
}

char			*ft_itoa_long_double_pf(long double n)
{
	char			*entier;
	size_t			len[2];
	long double		fl;
	int				i[3];

	i[1] = 0;
	i[2] = 6;
	(g_save.precision != -1) ? i[2] = g_save.precision : 0;
	if (n < 0)
	{
		n = n * -1;
		i[1] = 1;
	}
	norme(i[2], 0, 0, &n);
	entier = NULL;
	fl = n;
	len[1] = ft_len(&fl);
	len[0] = len[1];
	i[0] = 0;
	if (!(entier = ft_strnew(len[1] + i[2] + 2)))
		return (NULL);
	recup_entier(fl, len[1], &entier, &i[0]);
	fl = n - (long long unsigned int)n;
	(i[2] > 0) ? entier[i[0]] = '.' : 0;
	return (norme2(i, fl, &entier));
}
