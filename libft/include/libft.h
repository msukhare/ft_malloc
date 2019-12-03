/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:09:37 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/23 13:14:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# define BUFF_SIZE 80
# define BUFF_SIZE_GNL 50

typedef struct		s_gnl
{
	int				index;
	char			*p_line;
}					t_gnl;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_flag
{
	size_t			type;
	size_t			conv;
	size_t			minus;
	size_t			signe;
	size_t			diez;
	size_t			space;
	size_t			zero;
	int				min_nb;
	int				min_field;
	int				preci;
	size_t			field;
	size_t			pourcent;
	int				backzero;
	char			*p_var;
}					t_flag;
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(const char *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
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
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_rev(char *s1);
void				ft_swap(int *a, int *b);
void				ft_sorttab(int *tab_int, size_t len);
void				ft_putsplit(char **str);
void				ft_to_upper(char *str);
char				*ft_addsigne(char *str);
size_t				ft_strclen(const char *s, char c);
int					ft_putinbuff(const char *str, int *i, int *j, char *buff);
int					ft_putinbuffvar(t_flag *flag, int *j, char *buff);
void				ft_checksigne(char *str, int *i, t_flag *flag);
void				ft_checkfield(char *str, int *i, t_flag *flag);
void				ft_checkconv(char *p_flag, int *i, t_flag *flag);
void				ft_checktype(char c, t_flag *flag);
t_flag				*ft_getflag(const char *str, int *i);
char				*ft_addspace(char *p_var);
void				ft_mvdiez(char *str, int field);
void				ft_put_c_instring(char *str, char c, int size);
char				*ft_putfieldleft(char *p_field, char *p_var, t_flag *flag);
char				*ft_putfield(char *p_var, t_flag *flag);
void				ft_movesigne(char *new_pvar);
char				*ft_addzero(char *p_var, t_flag *flag, int size_char);
char				*ft_cutstring(char *p_var, int preci);
char				*ft_putpreci(char *p_var, t_flag *flag);
char				*ft_getstring(char *str);
char				*ft_returnp_var(char *p_var, t_flag *flag);
int					ft_getpreciuni(wchar_t *str, int preci);
char				*ft_get_charunic(wint_t c, t_flag *flag);
char				*ft_get_stringunic(wchar_t *str, t_flag *flag);
char				*ft_get_stringunic(wchar_t *str, t_flag *flag);
void				ft_splitbyteuni(char *p_uni, wint_t c, int nb_byte);
char				*ft_getuni(wint_t c);
char				*ft_ulltoa_base(unsigned long long nb, int type);
int					ft_checkvar(char *str);
char				*ft_putdiez(char *p_var, t_flag *flag);
char				*ft_lltoa(long long n);
char				*ft_getchar(char c, t_flag *flag);
char				*ft_get_convertion(va_list ap, t_flag *flag);
char				*ft_newvar(va_list ap, t_flag *flag);
int					ft_printf(const char *str, ...);
char				*ft_ulltoa(unsigned long long n);
char				*ft_strjoinfree(char *s1, char *s2);
int					ft_isspace(char c);
void				ft_putcstr_fd(char *str, int fd, char c);
int					ft_strccmp(char *s1, char *s2, char c);
int					ft_lentab(char **tab_char);
long				ft_atol(const char *str);
int					get_next_line(const int fd, char **line);
int					ft_if_c_in_str(char *str, char c);
#endif
