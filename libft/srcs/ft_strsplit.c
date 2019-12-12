/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:43:16 by pitirard     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 19:23:36 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_count_letter(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

int		ft_count_words(const char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	char				**dst;
	int					nb_words;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	if ((dst = malloc(sizeof(char*) * (nb_words + 1))) == NULL)
		return (NULL);
	while (nb_words > 0)
	{
		while (s[i] == c)
			i++;
		if (!(dst[j] = ft_strsub(s, i, ft_count_letter(s + i, c))))
			return (NULL);
		j++;
		while (s[i] && s[i] != c)
			i++;
		nb_words--;
	}
	dst[j] = NULL;
	return (dst);
}
