/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:53:10 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:22:40 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i[4];

	i[1] = 0;
	i[3] = -1;
	if (*find == '\0')
		return ((char*)&str[0]);
	while (str[i[1]] != '\0' && ++i[3] <= len)
	{
		i[0] = 0;
		i[2] = i[1];
		while (str[i[1]] == find[i[0]] && find[i[0]] != '\0' && i[3] != len)
		{
			i[0]++;
			i[3]++;
			i[1]++;
		}
		if (find[i[0]] == '\0')
			return ((char*)&str[i[2]]);
		i[1] = i[2] + 1;
		i[3] = i[2];
	}
	return (NULL);
}
