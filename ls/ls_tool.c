/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:55:38 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 17:48:30 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

char	*ft_getright(struct stat *s)
{
	char	*chmod;

	chmod = ft_strnew(10);
	chmod[0] = (s->st_mode & S_IRUSR) ? 'r' : '-';
	chmod[1] = (s->st_mode & S_IWUSR) ? 'w' : '-';
	chmod[2] = (s->st_mode & S_IXUSR) ? 'x' : '-';
	chmod[3] = (s->st_mode & S_IRGRP) ? 'r' : '-';
	chmod[4] = (s->st_mode & S_IWGRP) ? 'w' : '-';
	chmod[5] = (s->st_mode & S_IXGRP) ? 'x' : '-';
	chmod[6] = (s->st_mode & S_IROTH) ? 'r' : '-';
	chmod[7] = (s->st_mode & S_IWOTH) ? 'w' : '-';
	chmod[8] = (s->st_mode & S_IXOTH) ? 'x' : '-';
	return (chmod);
}

void	ft_len_size_lk(t_option **opt, t_info *info)
{
	while (info)
	{
		if ((info->name)[0] != '.' || (*opt)->opt_a)
		{
			if ((*opt)->len_l < (unsigned char) ft_strlen(info->link))
				(*opt)->len_l = (unsigned char) ft_strlen(info->link);
			if ((*opt)->len_o < (unsigned char) ft_strlen(info->owner))
				(*opt)->len_o = (unsigned char) ft_strlen(info->owner);
			if ((*opt)->len_g < (unsigned char) ft_strlen(info->group))
				(*opt)->len_g = (unsigned char) ft_strlen(info->group);
			if ((*opt)->len_s < (unsigned char) ft_strlen(info->size))
				(*opt)->len_s = (unsigned char) ft_strlen(info->size);
			(*opt)->total_blk += info->block;
		}
		info = info->next;
	}
}

char	ft_get_type(unsigned char type_nb)
{
	if (type_nb == 4)
		return ('d');
	else if (type_nb == 10)
		return ('l');
	else if (type_nb == 2)
		return ('c');
	else if (type_nb == 6)
		return ('b');
	else if (type_nb == 1)
		return ('p');
	else if (type_nb == 12)
		return ('s');
	else
		return ('-');
}

int		ft_getstat(char *nam, struct stat *s, t_info **new, struct dirent *d)
{
	if (((*new)->type = (unsigned char) ft_get_type(d->d_type)) == 'l')
		return (lstat(nam, s));
	return (stat(nam, s));
}

char	*ft_strjoin_path(const char *d, const char *name)
{
	char	*path;
	char	*tmp;

	if (d[ft_strlen(d) - 1] == '/')
		return (ft_strjoin(d, name));
	tmp = ft_strjoin(d, "/");
	if (tmp == NULL)
		return (NULL);
	path = ft_strjoin(tmp, name);
	free(tmp);
	return (path);
}
