/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 20:22:02 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 21:11:03 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct		s_road
{
	int				index;
	int				nbchar;
	char			*argument;
	char			*tmp;
	char			*large;
	int				c2;
	char			*signe;
}					t_road;

t_road				g_road;

typedef struct		s_option
{
	int				moins;
	int				plus;
	int				zero;
	int				space;
	int				diese;
}					t_option;

t_option			g_option;

typedef struct		s_save
{
	char			signe;
	char			type;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				grand_l;
	int				large;
	int				precision;
}					t_save;

t_save				g_save;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c,
					size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int,
					char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start,
					size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*,
					size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_iterative_power(int nb, int power);
int					ft_list_size(t_list *lst);
int					ft_strlen_c(char *str, char c);
t_list				*ft_list_last(t_list *lst);
char				*ft_strrev(char *str);
int					ft_sqrt(int nb);
int					ft_sqrt2(int nb);
int					ft_printf(const char *format, ...)
					 __attribute__((format(printf,1,2)));
int					treatment(va_list *args);
int					resolv_di(void);
int					skipmoin(char *tmp, int *moins);
int					swap(char **tmp);
int					place_moins(char *tmp);
int					resolv_s_large(int i, char *tmp, int size);
int					resolv_x(void);
int					resolv_f(void);
int					ft_atoi(const char *str);
int					utils_resolv_x(char *tmp, char *tmp2, char **large);
int					norme_di(char *tmp, int *moins, int i,
					char **space_plus);
int					norme_di2(size_t s, char *tmp, char **space_plus,
					int moins);
int					norme_di3(char **space_plus, char *tmp);
int					norme_di4(char **space_plus);
int					resolv_di_precision(char *tmp, int i);
int					resolv_di_moins(int moins);
int					resolv_di_size(char *tmp, int size, char *b,
					int moins);
int					resolv_di_plus(char **str);
int					resolv_norme_f(char *tmp);
int					resolv_norme_f2(char *tmp);
int					resolv_norme_f3(char *tmp);
char				*search_space(char *tmp);
char				*search_zero(char *tmp);
char				*ft_itoa_long_double_pf(long double n);
char				*ft_itoa_unsigned_pf(unsigned int n);
char				*ft_itoa_unsigned_long_pf(unsigned long long
					int n);
char				*ft_itoa_base_unsigned_long_pf(unsigned long
					long int n);
char				*ft_itoa_base_pf(long long int n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_itoa_pf(long long int n);
void				display(char *str, char a);
void				ini_strct(int a, int b, int c);
void				analyse(char *address_percent);

#endif
