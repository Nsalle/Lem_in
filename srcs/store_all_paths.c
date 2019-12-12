/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   store_all_paths.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 13:34:12 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:21:26 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_shortest_path(t_lem *lem)
{
	size_t	shortest;
	int		track_nb_path;

	track_nb_path = 0;
	shortest = lem->nb_room + 1;
	lem->path = lem->begin_path;
	lem->shortest_path = (int*)malloc(sizeof(int));
	while (track_nb_path < lem->nb_path)
	{
		if (get_tab_size(lem->path->path) < shortest)
		{
			shortest = get_tab_size(lem->path->path);
			free(lem->shortest_path);
			lem->shortest_path = tabdup(lem->path->path);
		}
		lem->path = lem->path->next;
		track_nb_path++;
	}
}

int		already_visited(int *path, int room)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (path[i] == room)
			return (1);
		i++;
	}
	return (0);
}

void	end_of_path(t_lem *lem, int *path)
{
	lem->path->path = tabdup(path);
	lem->path->next = (t_list_path*)malloc(sizeof(t_list_path));
	lem->path = lem->path->next;
	lem->path->next = NULL;
	lem->nb_path++;
}

int		try_to_find(char *line, t_lem *lem, int *path)
{
	int		i;

	if (line[lem->nb_room - 1] == '1')
	{
		add_to_path(path, 0);
		end_of_path(lem, path);
		return (1);
	}
	i = 1;
	while (i < lem->nb_room)
	{
		if (line[i] == '1')
		{
			if (!(already_visited(path, i)))
			{
				add_to_path(path, i);
				try_to_find(lem->room_matrix[i], lem, path);
				remove_last_path(path);
			}
		}
		i++;
	}
	return (0);
}

void	store_all_paths(t_lem *lem)
{
	int		*path;
	int		i;

	i = 0;
	lem->nb_path = 0;
	lem->begin_path = (t_list_path*)malloc(sizeof(t_list_path));
	lem->path = lem->begin_path;
	path = (int*)malloc(sizeof(int) * (lem->nb_room + 1));
	while (i < lem->nb_room + 1)
	{
		path[i] = 0;
		i++;
	}
	try_to_find(lem->room_matrix[0], lem, path);
	ft_printf("J'ai trouve %d paths\n\n", lem->nb_path);
	//print_all_paths(lem);
	get_shortest_path(lem);
	print_path(lem->shortest_path, lem);
}
