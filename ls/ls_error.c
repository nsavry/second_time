/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:57:58 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 16:34:42 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_dir_error(const char *dir)
{
	char	*str;

	str = ft_strjoin("ft_ls: ", dir);
	perror(str);
	free(str);
}

void	ft_put_err(t_list *err)
{
	while (err != NULL)
	{
		ft_error(err->content);
		err = err->next;
	}
}

void	ft_error(const char *name)
{
	DIR		*dir;

	dir = opendir(name);
	if (dir == NULL)
	{
		ft_dir_error(name);
		return ;
	}
	closedir(dir);
}
