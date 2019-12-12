/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 17:32:52 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:23:59 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	index;
	size_t	index2;
	size_t	i;

	index = 0;
	index2 = 0;
	if (*to_find == '\0')
		return ((char*)&str[0]);
	while (str[index2] != '\0')
	{
		index = 0;
		i = index2;
		while (str[index2] == to_find[index] && to_find[index] != '\0')
		{
			index++;
			index2++;
		}
		if (to_find[index] == '\0')
			return ((char*)&str[i]);
		else
			index2 = i + 1;
	}
	return (NULL);
}
