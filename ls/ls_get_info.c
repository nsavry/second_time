/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:11:59 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 16:35:10 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_fill_lst_info(DIR *dir, t_option *op, const char *d, t_info **inf)
{
	t_info			*new_info;
	struct dirent	*diren;

	while ((diren = readdir(dir)) != NULL)
	{
		new_info = ft_getinfo(d, diren, op);
		if (new_info != NULL)
		{
			if (op->opt_t == 0)
				ft_info_add(inf, new_info, &ft_infoadd_cmp);
			else
				ft_info_add(inf, new_info, &ft_infoadd_time);
		}
	}
}

char	*ft_fill_name(char *d_name, char *name, char c, t_option *opt)
{
	char	buf[1025];
	char	*tmp;
	char	*str;
	int		ret;

	if (c == 'l' && opt->opt_l != 0)
	{
		ret = readlink(name, buf, 1024);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		tmp = ft_strjoin(d_name, " -> ");
		str = ft_strjoin(tmp, buf);
		free(tmp);
		return (str);
	}
	else
		return (ft_strdup(d_name));
}

void	ft_fill_info(char *nam, struct stat *s, t_info **new, struct dirent *d)
{
	struct passwd	*p;
	struct group	*g;

	if (ft_getstat(nam, s, new, d) != 0)
	{
		ft_dir_error(d->d_name);
		ft_del((void **) new);
		return ;
	}
	p = getpwuid(s->st_uid);
	g = getgrgid(s->st_gid);
	(*new)->right = ft_getright(s);
	(*new)->link = ft_itoa((s->st_nlink));
	if (p == NULL)
		(*new)->owner = ft_itoa((int) (s->st_uid));
	else
		(*new)->owner = ft_strdup(p->pw_name);
	if (g == NULL)
		(*new)->group = ft_itoa((int) (s->st_gid));
	else
		(*new)->group = ft_strdup(g->gr_name);
	(*new)->size = ft_itoa((s->st_size));
	(*new)->date = (s->st_mtimespec.tv_sec);
	(*new)->block = s->st_blocks;
	(*new)->next = NULL;
}

t_info	*ft_getinfo(const char *direct, struct dirent *d, t_option *opt)
{
	t_info			*new;
	struct stat		*s;
	char			*name;

	new = (t_info*) malloc(sizeof(*new));
	s = (struct stat*) malloc(sizeof(*s));
	name = ft_strjoin_path(direct, d->d_name);
	if (name == NULL || s == NULL || new == NULL)
	{
		ft_del((void **) &name);
		ft_del((void **) &s);
		ft_del((void **) &new);
		return (NULL);
	}
	ft_fill_info(name, s, &new, d);
	if (new != NULL)
		new->name = ft_fill_name(d->d_name, name, new->type, opt);
	free(name);
	free(s);
	return (new);
}
