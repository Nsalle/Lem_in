/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:06:27 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:23:23 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	char	stock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (i >= j)
	{
		stock = str[j];
		str[j] = str[i];
		str[i] = stock;
		j++;
		i--;
	}
	return (str);
}
