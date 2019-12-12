/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parse_rooms.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:33:53 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 22:44:16 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	make_roomtab(t_lem *lem)
{
	int	i;

	lem->rooms = (t_rooms*)malloc(sizeof(t_rooms) * lem->nb_room);
	i = 1;
	while (i < lem->nb_room)
	{
		while (lem->tabfile[lem->curs][0] == '#')
			lem->curs++;
		lem->rooms[i].name = ft_strndup(lem->tabfile[lem->curs],
			ft_strcspn(lem->tabfile[lem->curs], " "));
		if (!ft_strcmp(lem->rooms[i].name, lem->start))
			ft_strdel(&lem->rooms[i--].name);
		else if (!ft_strcmp(lem->rooms[i].name, lem->end))
			ft_strdel(&lem->rooms[i--].name);
		i++;
		lem->curs++;
	}
	lem->rooms[0].name = ft_strdup(lem->start);
	lem->rooms[lem->nb_room - 1].name = ft_strdup(lem->end); // POSSIBLE FUITE ICI
}

void	get_room_names(char **r1, char **r2, char *str, t_lem *lem)
{
	int		i;
	int		j;
	char	foundboth;

	j = 0;
	foundboth = 0;
	i = ft_strcspn(str, "-");
	*r1 = ft_strndup(str, i);
	*r2 = ft_strdup(str + i + 1);
	while (j < lem->nb_room)
	{
		if ( !(ft_strcmp(*r1, lem->rooms[j].name)) || !(ft_strcmp(*r2, lem->rooms[j].name) ))
			foundboth++;
		j++;
	}
	if (foundboth < 2)
	{
		ft_strdel(r1);
		ft_strdel(r2);
		ft_putendl_fd("Wrong room name in your list of links\nERROR\n", 2);
		exit_after_rooms(lem);
	}
}

void	fill_matrix(t_lem *lem)
{
	char	*r1;
	char	*r2;
	int		i;
	int		j;

	while (lem->tabfile[lem->curs])
	{
		i = 0;
		j = 0;
		while (lem->tabfile[lem->curs] && lem->tabfile[lem->curs][0] == '#')
			lem->curs++;
		if (!(lem->tabfile[lem->curs]))
			break;
		get_room_names(&r1, &r2, lem->tabfile[lem->curs], lem);
		while (ft_strcmp(r1, lem->rooms[i].name))
			i++;
		while (ft_strcmp(r2, lem->rooms[j].name))
			j++;
		ft_strdel(&r1);
		ft_strdel(&r2);
		lem->room_matrix[i][j] = '1';
		lem->room_matrix[j][i] = '1';
		lem->curs++;
	}
}

void	init_matrix(t_lem *lem)
{
	int i;
	int j;

	lem->room_matrix = (char **)malloc(sizeof(char *) * (lem->nb_room + 1));
	i = 0;
	while (i < lem->nb_room)
	{
		j = 0;
		lem->room_matrix[i] = (char *)malloc(sizeof(char) * (lem->nb_room + 1));
		while (j < lem->nb_room)
		{
			lem->room_matrix[i][j] = '0';
			j++;
		}
		lem->room_matrix[i][j] = '\0';
		i++;
	}
	lem->room_matrix[i] = NULL;
}

void	parse_rooms(t_lem *lem)
{
	make_roomtab(lem);
	lem->curs = 0;
	while(!(ft_strchr(lem->tabfile[lem->curs], '-'))
		|| lem->tabfile[lem->curs][0] == '#')
		lem->curs++;
	check_roomerrors(lem);
	init_matrix(lem);
	fill_matrix(lem);
}
