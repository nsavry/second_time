/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:52:33 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 12:52:35 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_infoadd_cmp(t_info **lst, t_info *new)
{
	t_info	*tmp1;
	t_info	*tmp2;

	tmp1 = *lst;
	if (ft_strcmp(new->name, tmp1->name) < 0)
	{
		ft_infoadd(lst, new);
		return ;
	}
	tmp2 = tmp1->next;
	while (tmp2 != NULL)
	{
		if (ft_strcmp(new->name, tmp2->name) < 0)
		{
			new->next = tmp2;
			tmp1->next = new;
			return ;
		}
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	tmp1->next = new;
}

void	ft_infoadd_time(t_info **inf, t_info *new)
{
	t_info	*tmp1;
	t_info	*tmp2;

	tmp1 = *inf;
	if (new->date > tmp1->date)
	{
		ft_infoadd(inf, new);
		return ;
	}
	tmp2 = tmp1->next;
	while (tmp2 != NULL)
	{
		if (new->date > tmp2->date)
		{
			new->next = tmp2;
			tmp1->next = new;
			return ;
		}
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	tmp1->next = new;
}

void	ft_info_add(t_info **inf, t_info *new, void (*f)(t_info **, t_info *))
{
	if (*inf == NULL)
		*inf = new;
	else
		f(inf, new);
}

void	ft_infoadd(t_info **inf, t_info *new)
{
	new->next = *inf;
	*inf = new;
}
