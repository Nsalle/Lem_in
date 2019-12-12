/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 17:23:20 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:34:19 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		skip_multiple_coms(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[lem->curs + i][0] == '#')
		i++;
	return (i);
}

void	check_com(t_lem *lem)
{
	int		i;
	char	*tmp;

	i = skip_multiple_coms(lem);
	if (!(ft_strcmp(lem->tabfile[lem->curs], "##start")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->start = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		check_com_cut(lem, i, 1);
	}
	else if (!(ft_strcmp(lem->tabfile[lem->curs], "##end")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->end = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		check_com_cut(lem, i, 0);
	}
	else
		lem->curs++;
}

void	get_nb_ants(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[lem->curs][0] == '#')
		lem->curs++;
	lem->nb_ant = ft_atoi(lem->tabfile[lem->curs]);
	if (lem->nb_ant < 1 || lem->nb_ant > 2147483647)
	{
		ft_putstr_fd("Wrong number of ants, set : [1 to 2147483647]\n", 2);
		exit_early_parsing(lem);
	}
	lem->curs++;
}

void	get_nb_rooms(t_lem *lem)
{
	int	tmpcurs;

	tmpcurs = lem->curs;
	while (42)
	{
		if (lem->tabfile[lem->curs][0] == '#')
			check_com(lem);
		else if (ft_strchr(lem->tabfile[lem->curs], '-'))
			break ;
		else
		{
			lem->nb_room++;
			lem->curs++;
		}
	}
	if (lem->nb_room == 0 || lem->startfound != 1 || lem->endfound != 1)
	{
		ft_putendl_fd("Stricly need one starting and ending room", 2);
		exit_early_parsing(lem);
	}
	lem->curs = tmpcurs;
}

void	lem_parsing(t_lem *lem)
{
	char	*linefile;

	linefile = file_to_line();
	if (!(lem->tabfile = ft_strsplit(linefile, '\n')))
		exit(0);
	get_nb_ants(lem);
	get_nb_rooms(lem);
	ft_strdel(&linefile);
	parse_rooms(lem);
}
