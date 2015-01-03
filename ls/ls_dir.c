/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:14:15 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 18:37:19 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

t_list	*ft_getlist_directory(t_info *info, const char *directory)
{
	t_list	*lst;
	t_list	*new;
	char	*name;

	lst = NULL;
	while (info != NULL)
	{
		if (info->type == 'd' && ft_strcmp(info->name, ".") != 0
			&& ft_strcmp(info->name, "..") != 0)
		{
			name = ft_strjoin_path(directory, info->name);
			new = ft_lstnew(name, sizeof(*name) * (ft_strlen(name) + 1));
			free(name);
			if (lst == NULL)
				lst = new;
			else
				ft_lstadd_end(&lst, new);
		}
		info = info->next;
	}
	return (lst);
}

int		ft_directory_mask(const char *d)
{
	size_t	i;

	i = ft_strlen(d);
	while (i > 0 && d[i] != '/')
		i--;
	if ((i == 0 && d[i] == '.') || (d[i] == '/' && d[i + 1] == '.'))
		return (1);
	return (0);
}

int		ft_get_dir(int ac, char **av, t_list **dir, t_option *opt)
{
	t_list	*err;
	t_list	*fil;
	int		i;

	i = 1;
	err = NULL;
	fil = NULL;
	while (i < ac && ft_isoption(av[i]) != 0)
		i++;
	if (i< ac && ft_strcmp(av[i], "--") == 0)
		i++;
	while (i < ac)
	{
		ft_lstchoose(av[i], &err, &fil, dir);
		i++;
	}
	if (err == NULL && fil == NULL && *dir == NULL)
		return (0);
	ft_put_err(err);
	ft_lstdel(&err, &ft_memdel_size);
	ft_ls_file_list(opt, fil);
	ft_lstdel(&fil, &ft_memdel_size);
	return (1);
}
