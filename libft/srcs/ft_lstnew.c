/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 15:04:14 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:10:10 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cpy_content;
	size_t	cpy_size;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (content != NULL)
	{
		cpy_content = ft_memalloc(content_size);
		ft_memcpy(cpy_content, content, content_size);
		cpy_size = content_size;
		new->content = cpy_content;
		new->content_size = cpy_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
