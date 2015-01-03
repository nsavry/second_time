/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:11:59 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 13:13:19 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_find_name(t_list *new, t_list **err, t_list **dir)
{
	char	*d;
	char	*n;
	char	*name;
	int		ret;

	name = (char *) new->content;
	if ((n = ft_strrchr(name, '/')) == NULL)
		ret = ft_find_file_dir(".", name);
	else
	{
		d = ft_strsub(name, 0, new->content_size - ft_strlen(n));
		n++;
		ret = ft_find_file_dir(d, n);
		free(d);
	}
	if (ret == 0)
		ft_lst_add(err, new, &ft_lstadd_cmp);
	else
		ft_lst_add(dir, new, &ft_lstadd_cmp);
}

int		ft_find_file_dir(const char *direct, const char *file)
{
	DIR				*dir;
	struct dirent	*diren;

	dir = opendir(direct);
	if (dir == NULL)
		return (0);
	while ((diren = readdir(dir)) != NULL)
	{
		if (ft_strcmp(diren->d_name, file) == 0)
			return (1);
	}
	closedir(dir);
	return (0);
}

void	ft_lstchoose(const char *nam, t_list **err, t_list **fil, t_list **dir)
{
	DIR		*d;
	t_list	*new;

	new = ft_lstnew(nam, sizeof(*nam) * (ft_strlen(nam) + 1));
	if (new != NULL)
	{
		d = opendir(nam);
		if (d == NULL)
		{
			if (errno == 20 || errno == 62)
				ft_lst_add(fil, new, &ft_lstadd_cmp);
			else if (errno == 2)
				ft_lst_add(err, new, &ft_lstadd_cmp);
			else
				ft_find_name(new, err, dir);
			return ;
		}
		ft_lst_add(dir, new, &ft_lstadd_cmp);
		closedir(d);
	}
}
