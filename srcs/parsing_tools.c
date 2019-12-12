/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_tools.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:57:16 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 00:11:22 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	check_com_cut(t_lem *lem, int i, char start)
{
	if (start)
	{
		lem->startindex = lem->curs + i;
		lem->startfound++;
	}
	else
	{
		lem->endindex = lem->curs + i;
		lem->endfound++;
	}
	lem->curs += 1 + i;
	lem->nb_room++;
}

char	*clean_join(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2)))
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
		exit(0);
	}
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\n';
	ret[i + 1] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}

char	*file_to_line(void)
{
	char	*line;
	char	*ret;

	if (!(ret = ft_strdup("#HEAD\n")))
		exit(0);
	while (get_next_line(0, &line))
		ret = clean_join(ret, line);
	return (ret);
}
