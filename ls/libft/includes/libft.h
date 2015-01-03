/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:42:25 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/07 03:42:37 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 128

 typedef struct		s_list
 {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
 }					t_list;

 void		*ft_memset(void *b, int c, size_t len);
 void		ft_bzero(void *s, size_t n);
 void		*ft_memcpy(void *s1, const void *s2, size_t n);
 void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
 void		*ft_memmove(void *s1, const void *s2, size_t n);
 void		*ft_memchr(const void *s, int c, size_t n);
 int		ft_memcmp(const void *s1, const void *s2, size_t n);
 size_t		ft_strlen(const char *s);
 char		*ft_strdup(const char *s1);
 char		*ft_strcpy(char *s1, const char *s2);
 char		*ft_strncpy(char *s1, const char *s2, size_t n);
 char		*ft_strcat(char *s1, const char *s2);
 char		*ft_strncat(char *s1, const char *s2, size_t n);
 size_t		ft_strlcat(char *dst, const char *src, size_t size);
 char		*ft_strchr(const char *s1, int c);
 char		*ft_strrchr(const char *s1, int c);
 char		*ft_strstr(const char *s1, const char *s2);
 char		*ft_strnstr(const char *s1, const char *s2, size_t n);
 int		ft_strcmp(const char *s1, const char *s2);
 int		ft_strncmp(const char *s1, const char *s2, size_t n);
 int		ft_atoi(const char *str);
 int		ft_isalpha(int c);
 int		ft_isdigit(int c);
 int		ft_isalnum(int c);
 int		ft_isascii(int c);
 int		ft_isprint(int c);
 int		ft_toupper(int c);
 int		ft_tolower(int c);
 void		*ft_memalloc(size_t size);
 void		ft_memdel(void **ap);
 char		*ft_strnew(size_t size);
 void		ft_strdel(char **as);
 void		ft_strclr(char *s);
 void		ft_striter(char *s, void (*f)(char *));
 void		ft_striteri(char *s, void (*f)(unsigned int, char *));
 char		*ft_strmap(char const *s, char (*f)(char));
 char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
 int		ft_strequ(char const *s1, char const *s2);
 int		ft_strnequ(char const *s1, char const *s2, size_t n);
 char		*ft_strsub(char const *s, unsigned int start, size_t len);
 char		*ft_strjoin(char const *s1, char const *s2);
 char		*ft_strtrim(char const *s);
 char		**ft_strsplit(char const *s, char c);
 char		*ft_itoa(int n);
 void		ft_putchar(char c);
 void		ft_putstr(char const *s);
 void		ft_putendl(char const *s);
 void		ft_putnbr(int n);
 void		ft_putchar_fd(char c, int fd);
 void		ft_putstr_fd(char const *s, int fd);
 void		ft_putendl_fd(char const *s, int fd);
 void		ft_putnbr_fd(int n, int fd);
 t_list		*ft_lstnew(void const *content, size_t content_size);
 void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
 void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
 void		ft_lstadd(t_list **alst, t_list *new);
 void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
 t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
 void		ft_lstaddend(t_list **alst, char *buff);
 void		ft_printlst(t_list **alst);
 int		gnl(int fd, char **buff);
 void		ft_strtrimc(char **s, char c);

 size_t	ft_min(size_t size1, size_t size2);
size_t	ft_max(size_t size1, size_t size2);
void	ft_del(void **p);
void	ft_lstadd_cmp(t_list **lst, t_list *new);
void	ft_lstadd_rcmp(t_list **lst, t_list *new);
void	ft_memdel_size(void *content, size_t size);
void	ft_lstadd_end(t_list **alst, t_list *new);
void	ft_lstdel_mem(t_list **lst);
void	ft_lst_reverse(t_list **lst);
void	ft_lst_add(t_list **lst, t_list *new, void (*f)(t_list **, t_list *));

#endif /* !LIBFT_H */