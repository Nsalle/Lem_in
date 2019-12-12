/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 09:40:03 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 18:59:49 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	size_t		index;
	long int	nb;
	int			negatif;

	index = 0;
	nb = 0;
	negatif = 0;
	while (str[index] == '\f' || str[index] == '\t' || str[index] == '\n' ||
			str[index] == '\r' || str[index] == '\v' || str[index] == ' ')
		index++;
	if (str[index] == 45)
		negatif = 1;
	if (str[index] == 45 || str[index] == 43)
		index++;
	while (str[index] >= 48 && str[index] <= 57)
	{
		nb = nb * 10;
		nb = nb + (str[index] - 48);
		index++;
	}
	if (negatif)
		return (-nb);
	else
		return (nb);
}
