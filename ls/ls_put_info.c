/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:19:21 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 18:15:40 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_infoput_file(t_info *inf, t_option *opt)
{
	ft_len_size_lk(&opt, inf);
	while (inf != NULL)
	{
		if (opt->opt_l)
		{
			ft_putchar(inf->type);
			ft_putstr(inf->right);
			ft_putchar(' ');
			ft_put_space_before(opt->len_l, inf->link);
			ft_put_space_after(opt->len_o, inf->owner);
			ft_putchar(' ');
			ft_put_space_after(opt->len_g, inf->group);
			ft_putchar(' ');
			ft_put_space_before(opt->len_s, inf->size);
			ft_putstr(" ");
			ft_putdate(inf->date);
			ft_putstr(" ");
		}
		ft_putendl(inf->name);
		inf = inf->next;
	}
	ft_reset_option(&opt);
}

void	ft_putls(t_info **info, t_option *opt, const char *dir, int nb)
{
	t_list	*rec_list;

	rec_list = NULL;
	if (opt->opt_r != 0)
		ft_info_reverse(info);
	if (nb == 0 || opt->opt_a != 0 || ft_directory_mask(dir) == 0)
	{
		ft_putendl("");
		ft_putstr(dir);
		ft_putendl(":");
		ft_infoput(*info, opt);
	}
	ft_reset_option(&opt);
	if (opt->opt_R != 0)
	{
		rec_list = ft_getlist_directory(*info, dir);
		ft_infodel(info);
		ft_ls_option_list(opt, rec_list, nb + 1);
	}
	ft_lstdel_mem(&rec_list);
}

void	ft_infoput_elem(t_info *inf, t_option *opt)
{
	if ((inf->name)[0] == '.' && opt->opt_a == 0)
		return ;
	if (opt->opt_l)
	{
		ft_putchar(inf->type);
		ft_putstr(inf->right);
		ft_putchar(' ');
		ft_put_space_before(opt->len_l, inf->link);
		ft_put_space_after(opt->len_o, inf->owner);
		ft_putchar(' ');
		ft_put_space_after(opt->len_g, inf->group);
		ft_putchar(' ');
		ft_put_space_before(opt->len_s, inf->size);
		ft_putstr(" ");
		ft_putdate(inf->date);
		ft_putstr(" ");
	}
	ft_putendl(inf->name);
}

void	ft_infoput(t_info *inf, t_option *opt)
{
	if (opt->opt_l)
	{
		ft_putstr("total ");
		ft_putnbr(opt->total_blk);
		ft_putchar('\n');
	}
	while (inf != NULL)
	{
		ft_infoput_elem(inf, opt);
		inf = inf->next;
	}
}
