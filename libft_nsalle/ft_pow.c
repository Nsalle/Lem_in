/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 21:19:47 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 21:19:58 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_pow(int nb, int exp)
{
	int rep;

	rep = nb;
	while (exp-- != 1)
		rep *= nb;
	return (rep);
}
