/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/17 20:41:39 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:33:07 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft_nsalle/libft.h"
# include "../sdl2/SDL.h"

typedef struct			s_list_answ
{
	char				*line;
	struct t_list_answ	*next;
}						t_list_answ;

typedef struct			s_list_path
{
	int					*path;
	struct s_list_path	*next;
}						t_list_path;

typedef struct			s_ant
{
	SDL_Rect			pos;
	int					**path;
	int					nbmoves;
	int					turn;
}						t_ant;

typedef struct			s_room
{
	int					x;
	int					y;
}						t_room;

typedef struct			s_rooms
{
	char				*name;
	char				start;
	char				end;
}						t_rooms;

typedef struct			s_lem
{
	char				**room_matrix;
	char				**tabfile;
	char				startfound;
	char				endfound;
	int					startindex;
	int					endindex;
	int					curs;
	int					**room_coords;
	int					biggestxcoord;
	int					biggestycoord;
	int					***turns;
	char				*start;
	char				*end;
	int					i_parsingline;
	int					*shortest_path;
	int					nb_path;
	t_rooms				*rooms;
	int					nb_room;
	long long int		nb_ant;

	int					nb_turn;
	t_list_answ			*begin_answer;
	t_list_answ			*answer;
	t_list_path			*begin_path;
	t_list_path			*path;
}						t_lem;

typedef	struct			s_visulem
{
	SDL_Window			*window;
	uint8_t				room_size;
	SDL_Renderer		*renderer;
	SDL_Renderer		*refreshed_r;
	SDL_Texture			*background;
	SDL_Rect			bgrect;
	SDL_Rect			startroom;
	SDL_Rect			endroom;
	SDL_Rect			antrect;
	t_room				*rooms;
	t_ant				*ants;
	char				bool_end;
}						t_visulem;

/***************************PARSER/VISU*******************************/
void					exit_lemin(void);
void					lem_parsing(t_lem *lem);
void					exit_early_parsing(t_lem *lem);
void					exit_after_rooms(t_lem *lem);

char					*clean_join(char *s1, char *s2);
char					*file_to_line(void);

void					parse_rooms(t_lem *lem);
void					remove_paths(t_lem *lem);

void					check_dupe_roomname(t_lem *lem);
void					check_com_cut(t_lem *lem, int i, char start);
void					check_roomerrors(t_lem *lem);

void					parse_coords(t_lem *lem);
void					check_coords(char **tab, t_lem *lem);
void					visu_lemin(t_lem *lem);
int						drawalllines(t_lem *lem, t_visulem *vs, t_room *room);
int						print_all(t_visulem *vs, t_lem *lem);
int						create_ants(t_visulem *vs, t_lem *lem);
void					free_path(t_ant ant);
void					error_init(t_lem *lem, t_visulem *vs, uint8_t ret);
int						ret_msg(uint8_t i, char *msg);
void					init_items(t_lem *lem, t_visulem *vs);
int						bresenham(SDL_Rect *rect, int x2, int y2, int **path);
void					settings(SDL_Event event, t_visulem *vs);
void					change_ant_pos(t_visulem *vs, t_lem *lem);
void					allmoves(t_lem *lem, t_visulem *vs);
void					parse_answer(t_lem *lem, t_visulem *vs);

int						find_end(t_lem *lem);
void					store_all_paths(t_lem *lem);
int						*tabdup(int	*tab);
void					remove_last_path(int *path);
void					add_to_path(int *path, int c);
size_t					get_tab_size(int *tab);

void					test(t_lem *lem);
void					print_all_paths(t_lem *lem);
void					print_path(int *path, t_lem *lem);
#endif
