/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_size.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:08:09 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:08:20 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_list_size(t_list *lst)
{
	int	compteur;

	compteur = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		compteur++;
	}
	return (compteur);
}
