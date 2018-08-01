/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:52:17 by golliet           #+#    #+#             */
/*   Updated: 2018/06/18 11:42:40 by golliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_listlibft
{
	void			*content;
	size_t			content_size;
	struct s_listlibft	*next;
}					t_listlibft;

typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tablb;
}					t_stock_par;


void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				**ft_sstrnew(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strdupfree(char *s1);
char				**ft_sstrdup(char **s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strlcpy(char *dst, const char *src, int *len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
size_t				ft_strcountoccur(const char *str, char search);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
char				*lltoa(long long n);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strindexchr(const char *str, char search);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoc(const char *s, int *c);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
unsigned long long	ft_atoul(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
char				*ft_chardup(const char s1);
int					ft_tolower(int c);
int					ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubfree(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, size_t tofree);
char				*ft_strtrim(char const *s);
char				*ft_stoa(short n);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long n, int base);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, int base);
char				*ft_ultoa_base(unsigned long long n, int base);
char				**ft_strsplit(char const *s, char c);
int					ft_isspace(int c);
int					ft_isnegative(int *n);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				**ft_split_whitespaces(char *str);
char				**ft_split_whitespaces_spec(char *str);
size_t				ft_sstrlen(char **str);
int					get_next_line(int fd, char **line);
t_listlibft			*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_listlibft **alst, t_listlibft *new);
char				*ft_charcat(char *s1, const char s2);
long long			ft_iterative_power(long long nb, long long power);
char				*ft_chardup_spec(const char s1);
void				lltoanomalloc(long long n, char *toadd);
#endif
