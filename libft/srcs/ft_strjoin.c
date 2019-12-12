/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 17:44:49 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:19:00 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = NULL;
	if (s1 == NULL || s2 == NULL || !(str = (char*)malloc(sizeof(*str) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j] = ((char)s1[i]);
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = ((char)s2[i]);
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
