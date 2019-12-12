/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 20:18:37 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:20:17 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	i;

	if (f == NULL || s == NULL)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s) + 1))))
		return (NULL);
	s2 = ft_strcpy(s2, s);
	i = 0;
	while (s[i])
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	return (s2);
}
