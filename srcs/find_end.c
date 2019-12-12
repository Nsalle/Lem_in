/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_end.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 18:12:31 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 14:30:44 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

// #include "../includes/lemin.h"


// void		remove_last_path(int *path)
// {
// 	int	i;

// 	i = 0;
// 	while (path[i] != 0)
// 		i++;
// 	path[i - 1] = 0;
// }

// void	print_path(int *path, t_lem *lem)
// {
// 	int		i;

// 	i = 0;
// 	ft_printf("%s-", lem->rooms[0].name);
// 	while (path[i])
// 	{
// 		ft_printf("%s-", lem->rooms[path[i]].name);
// 		i++;
// 	}
// 	ft_printf("%s\n", lem->end);
// }

// void	add_to_path(int *path, int c)
// {
// 	int		i;

// 	i = 0;
// 	while(path[i] != 0)
// 		i++;
// 	path[i] = c;
// }

// int		already_visited(int *path, int room)
// {
// 	int		i;

// 	i = 0;
// 	while (path[i])
// 	{
// 		if (path[i] == room)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int		try_to_find(char* line, t_lem* lem, int *path)
// {
// 	int		i;

// 	if (line[lem->nb_room - 1]  == '1')
// 	{
// 		print_path(path, lem);
// 		return (1);
// 	}

// 	i = 1;
// 	while (i < lem->nb_room)
// 	{
// 		if (line[i] == '1')
// 		{
// 			if (!(already_visited(path, i)))
// 			{
// 				add_to_path(path, i);
// 				if (try_to_find(lem->room_matrix[i], lem, path))
// 					return (1);
// 			}
// 			//remove_last_path(path);
// 		}
// 		i++;
// 	}
// 	return(0);
// }

// int		find_end(t_lem *lem)
// {
// 	int		*path;
// 	int		i;

// 	i = 0;
// 	path = (int*)malloc(sizeof(int) * (lem->nb_room + 1));
// 	while (i < lem->nb_room + 1)
// 	{
// 		path[i] = 0;
// 		i++;
// 	}
// 	ft_printf("test: %d\n", path[1]);
// 	if (try_to_find(lem->room_matrix[0], lem, path))
// 	{
// 		free(path);
// 		return (1);
// 	}
// 	free(path);
// 	return (0);
// }