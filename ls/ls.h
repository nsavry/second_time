/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:28:26 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 18:21:31 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/includes/libft.h"

typedef struct		s_option
{
	unsigned char	opt_l;
	unsigned char	opt_R;
	unsigned char	opt_a;
	unsigned char	opt_r;
	unsigned char	opt_t;
	unsigned char	len_l;
	unsigned char	len_o;
	unsigned char	len_g;
	unsigned char	len_s;
	quad_t			total_blk;
}					t_option;

typedef struct		s_info
{
	char			*name;
	unsigned char	type;
	char			*right;
	char			*link;
	char			*owner;
	char			*group;
	char			*size;
	time_t			date;
	quad_t			block;
	struct s_info	*next;
}					t_info;

void		ft_ls_simple(void);
void		ft_ls_option(t_option *, const char *, int);
void		ft_ls_file(char *, t_option *, t_info **);
void		ft_ls_file_dir(char *, char *, t_option *, t_info **);

void		ft_infoadd_cmp(t_info **, t_info *);
void		ft_infoadd_time(t_info **, t_info *);
void		ft_info_add(t_info **, t_info *, void (*f)(t_info **, t_info *));
void		ft_infoadd(t_info **, t_info *);

t_list		*ft_getlist_directory(t_info *, const char *);
int			ft_directory_mask(const char *);
int			ft_get_dir(int , char **, t_list **, t_option *);

void		ft_dir_error(const char *);
void		ft_put_err(t_list *);
void		ft_error(const char *);

void		ft_ls_option_list(t_option *, t_list *, int);
t_list		*ft_getfile(int , char **);
void		ft_ls_file_list(t_option *, t_list *);

void		ft_find_name(t_list *, t_list **, t_list **);
int			ft_find_file_dir(const char *, const char *);
void		ft_lstchoose(const char *, t_list **, t_list **, t_list **);

void		ft_fill_lst_info(DIR *, t_option *, const char *, t_info **);
char		*ft_fill_name(char *, char *, char, t_option *);
void		ft_fill_info(char *, struct stat *, t_info **, struct dirent *);
t_info		*ft_getinfo(const char *, struct dirent *, t_option *);

void		ft_infodel(t_info **);
void		ft_info_reverse(t_info **);
void		ls_choose_add_info(t_info **, t_info *, unsigned char);

t_option	*ft_newoption(void);
int			ft_isoption(char *);
void		ft_reset_option(t_option **);
void		ft_find_option(char **, t_option **, int);
t_option	*ft_getoption(int, char **);

time_t		ft_diff_date(time_t, time_t);
void		ft_putdate(time_t);

void		ft_infoput_file(t_info *, t_option *);
void		ft_putls(t_info **, t_option *, const char *, int);
void		ft_infoput_elem(t_info *, t_option *);
void		ft_infoput(t_info *, t_option *);

void		ft_put_space_before(unsigned char, char *);
void		ft_put_space_after(unsigned char, char *);

char		*ft_getright(struct stat *);
void		ft_len_size_lk(t_option **, t_info *);
char		ft_get_type(unsigned char);
int			ft_getstat(char *, struct stat *, t_info **, struct dirent *);
char		*ft_strjoin_path(const char *, const char *);

#endif /* !LS_H */
