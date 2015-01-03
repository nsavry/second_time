/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 18:51:45 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 17:07:55 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_ls_option_list(t_option *opt, t_list *file, int nb)
{
	while (file != NULL)
	{
		ft_ls_option(opt, file->content, nb);
		file = file->next;
	}
}

t_list	*ft_getfile(int ac, char **av)
{
	t_list	*lst;
	t_list	*new;
	int		i;

	i = 1;
	lst = NULL;
	while ((i < ac && av[i][0] == '-')
		   && (av[i][1] != '\0' || (av[i][1] == '-' && av[i][2] == '\0')))
		i++;
	while (i < ac)
	{
		new = ft_lstnew(av[i], sizeof(av[i]) * (ft_strlen(av[i]) + 1));
		if (new != NULL)
		{
			if (lst == NULL)
				lst = new;
			else
				ft_lstadd_cmp(&lst, new);
		}
		i++;
	}
	return (lst);
}

void	ft_ls_file_list(t_option *opt, t_list *files)
{
	t_info	*info;
	char	*f;
	char	*dir;
	char	*name;

	info = NULL;
	while (files != NULL)
	{
		name = (char *) files->content;
		if ((f = ft_strrchr(name, '/')) == NULL)
			ft_ls_file(name, opt, &info);
		else
		{
			dir = ft_strsub(name, 0, files->content_size - ft_strlen(f));
			f++;
			ft_ls_file_dir(dir, f, opt, &info);
			free(dir);
		}
		files = files->next;
	}
	if (opt->opt_r != 0)
		ft_info_reverse(&info);
	ft_infoput_file(info, opt);
	ft_infodel(&info);
}
