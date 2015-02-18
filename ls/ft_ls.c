/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:47:20 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 18:14:27 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_ls_simple(void)
{
	t_option	*opt;

	opt = ft_newoption();
	ft_ls_option(opt, ".", 0);
	free(opt);
}

void	ft_ls_option(t_option *opt, const char *directory, int nb)
{
	DIR				*dir;
	t_info			*info;

	info = NULL;
	dir = opendir(directory);
	if (dir == NULL)
	{
		ft_dir_error(directory);
		return ;
	}
	ft_fill_lst_info(dir, opt, directory, &info);
	ft_len_size_lk(&opt, info);
	if (info != NULL)
		ft_putls(&info, opt, directory, nb);
	ft_infodel(&info);
	closedir(dir);
}

void	ft_ls_file(char *file, t_option *opt, t_info **inf)
{
	DIR				*d;
	struct dirent	*diren;
	t_info			*new_info;

	d = opendir(".");
	if (d == NULL)
		return ;
	while ((diren = readdir(d)) != NULL)
	{
		if (ft_strcmp(file, diren->d_name) == 0)
		{
			new_info = ft_getinfo(".", diren, opt);
			if (new_info != NULL)
				ls_choose_add_info(inf, new_info, opt->opt_t);
		}
	}
	closedir(d);
}

void	ft_ls_file_dir(char *dir, char *file, t_option *opt, t_info **inf)
{
	DIR				*d;
	struct dirent	*diren;
	t_info			*new_info;
	char			*name;

	d = opendir(dir);
	if (d == NULL)
		return ;
	while ((diren = readdir(d)) != NULL)
	{
		if (ft_strcmp(file, diren->d_name) == 0)
		{
			new_info = ft_getinfo(dir, diren, opt);
			if (new_info != NULL)
			{
				name = new_info->name;
				new_info->name = ft_strjoin_path(dir, name);
				free(name);
				ls_choose_add_info(inf, new_info, opt->opt_t);
			}
		}
	}
	closedir(d);
}
