/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:15:24 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 20:25:12 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "garbage_collector.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_index
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	size_t	check;
}	t_index;

#ifndef LIST
# define LIST 
typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
#endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// GNL
char	*get_next_line(int fd);
size_t	ft_checklen(char *str, char str_line);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_check_new_line(char *str);
char	*ft_clean_line(char *line);
//Add on
int		ft_charcmp(char c, char to_cmp);
char	*ft_str_free_s1_join(char *s1_to_g_free, char *s2);
int		ft_str_setonly(char *str, char *set);
size_t	ft_wdcount(const char *str, char c);
void	*ft_free_all(char **tab);
// ft_tab_str.c
char	**ft_make_tabstr(void);
char **ft_temptab_totab(char **tab_dest, char **tab_src);
char	**ft_tabstr_addback(char *str, char **tab_str);
size_t	ft_tabstr_len(char **tabstr);
char	**ft_tabstr_copy(char **tabstr);
void	ft_print_tabstr(char **tabstr);
//ft_at_leats.c
int		ft_atleast_char(char *str, char c);
int		ft_atleast_set(char *str, char *set);
int		ft_tabatleast_char(char **tab, char c);
int		ft_tabatleast_set(char **tab, char *set);
void	ft_init_zero(t_index *i);
//ft_count_char.c
size_t	ft_count_char(char *str, char c);
size_t	ft_tabcount_char(char **tab, char c);
int		ft_findchar(char *str, char c);
t_point	ft_tab_findchar(char **tab, char c);
void	ft_init_t_point(t_point *index);

#endif
