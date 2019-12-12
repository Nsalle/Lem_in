/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:02:01 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:15:09 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_tabfile(t_lem *lemin)
{
	int	i;

	i = 0;
	while (lemin->tabfile[i] != NULL)
	{
		free(lemin->tabfile[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_lem			lemin;
	char			bool_visu;
	int		i;

	i = -1;
	ft_bzero((void*)&lemin, sizeof(t_lem));
	while (++i < lemin.nb_room)
		ft_bzero((void*)&lemin.rooms[i], sizeof(t_rooms));
	bool_visu = 0;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
		bool_visu = 1;
	lem_parsing(&lemin);
	remove_paths(&lemin);
	//test(&lemin);
	if (!bool_visu)
		free_tabfile(&lemin);
	// if (find_end(&lemin))
	// 	ft_printf("J'ai trouvé la fin\n");
	// else
	// 	ft_printf("Pas de fin\n");
	store_all_paths(&lemin);
	ft_putendl("");
	if (bool_visu)
	{
		parse_coords(&lemin);
		free_tabfile(&lemin);
		visu_lemin(&lemin);
	}
	return (0);
}

