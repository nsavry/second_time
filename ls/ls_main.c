/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:46:59 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 18:37:33 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

int		main(int ac, char **av)
{
	t_option	*option;
	t_list		*dir;

	dir = NULL;
	if (ac == 1)
		ft_ls_simple();
	else
	{
		option = ft_getoption(ac, av);
		if (option != NULL)
		{
			if (ft_get_dir(ac, av, &dir, option) != 0)
			{
				ft_ls_option_list(option, dir, 0);
				ft_lstdel(&dir, &ft_memdel_size);
			}
			else
				ft_ls_option(option, ".", 0);
			free(option);
		}
		else
			ft_putendl_fd("usage: ft_ls [-Ralrt] [file ...]", 2);
	}
	return (0);
}
