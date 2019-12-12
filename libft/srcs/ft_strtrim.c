/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 18:28:33 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:24:32 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tempo;
	char	*str;
	size_t	fin;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!(tempo = (char*)malloc(sizeof(*tempo) * (ft_strlen(s) + 1))))
		return (NULL);
	tempo = ft_strcpy(tempo, s);
	fin = ft_strlen(tempo);
	while (tempo[fin - 1] == ' ' || tempo[fin - 1] == '\n' ||
			tempo[fin - 1] == '\t')
		fin--;
	if (!(str = (char*)malloc(sizeof(*str) * (fin + 1))))
		return (NULL);
	str[fin] = '\0';
	while (fin--)
		str[fin] = tempo[fin];
	return (str);
}
