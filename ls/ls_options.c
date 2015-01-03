/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 18:40:44 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 18:31:06 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_option	*ft_newoption(void)
{
	t_option	*opt;

	opt = (t_option *) malloc(sizeof(*opt));
	if (opt == NULL)
		return (NULL);
	opt->opt_l = 0;
	opt->opt_R = 0;
	opt->opt_a = 0;
	opt->opt_r = 0;
	opt->opt_t = 0;
	opt->len_l = 0;
	opt->len_o = 0;
	opt->len_g = 0;
	opt->len_s = 0;
	opt->total_blk = 0;
	return (opt);
}

int			ft_isoption(char *op)
{
	int		i;

	i = 1;
	if (op[0] != '-' || op[1] == '\0')
		return (0);
	if (ft_strcmp(op, "--") == 0)
		return (0);
	while (op[i] != '\0')
	{
		if (op[i] != 'l' && op[i] != 'R' && op[i] != 'a'
			&& op[i] != 'r' && op[i] != 't')
			return (0);
		i++;
	}
	return (1);
}

void		ft_reset_option(t_option **opt)
{
	(*opt)->len_l = 0;
	(*opt)->len_o = 0;
	(*opt)->len_g = 0;
	(*opt)->len_s = 0;
	(*opt)->total_blk = 0;
}

void		ft_find_option(char **av, t_option **opt, int i)
{
	int		j;

	j = 1;
	while (av[i][j] && *opt != NULL)
	{
		if (av[i][j] == 'l')
			(*opt)->opt_l = 1;
		else if (av[i][j] == 'R')
			(*opt)->opt_R = 1;
		else if (av[i][j] == 'a')
			(*opt)->opt_a = 1;
		else if (av[i][j] == 'r')
			(*opt)->opt_r = 1;
		else if (av[i][j] == 't')
			(*opt)->opt_t = 1;
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(av[i][j], 2);
			ft_putchar_fd('\n', 2);
			free(*opt);
			*opt = NULL;
		}
		j++;
	}
}

t_option	*ft_getoption(int ac, char **av)
{
	t_option	*opt;
	int			i;

	opt = ft_newoption();
	if (opt == NULL)
		return (NULL);
	i = 1;
	while (i < ac && opt != NULL)
	{
		if (av[i][0] != '-'|| av[i][1] == '\0'
			|| (av[i][1] == '-' && av[i][2] == '\0'))
			return (opt);
		ft_find_option(av, &opt, i);
		i++;
	}
	return (opt);
}
