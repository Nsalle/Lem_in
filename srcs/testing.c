/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/04 16:28:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 14:28:32 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../includes/lemin.h"

void	print_path(int *path, t_lem *lem)
{
	int		i;

	i = 0;
	ft_printf("%s-", lem->rooms[0].name);
	while (path[i])
	{
		ft_printf("%s-", lem->rooms[path[i]].name);
		i++;
	}
	ft_printf("%s\nThe path is %d long\n", lem->rooms[lem->nb_room - 1].name, i + 1);
}

void	print_all_paths(t_lem *lem)	
{
	int		track_nb_path;

	track_nb_path = 0;
	lem->path = lem->begin_path;
	while (track_nb_path < lem->nb_path)
	{
		print_path(lem->path->path, lem);
		lem->path = lem->path->next;
		track_nb_path++;
	}
}

void	test(t_lem *lem)
{
	ft_printf("Nombre de fourmis: %lld\n", lem->nb_ant);
	ft_printf("Nombre de salles: %d\n", lem->nb_room);
	ft_printf("La salle de depart est: '%s'\n", lem->start);
	ft_printf("La salle de fin est   : '%s'\n", lem->end);

	ft_putendl("\n");
	int i = 0;
	while (lem->room_matrix[i])
	{
		ft_putendl(lem->room_matrix[i]);
		i++;
	}
	ft_putendl("");
}
