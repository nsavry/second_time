/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:52:55 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 17:55:29 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_infodel(t_info **info)
{
	while (*info != NULL)
	{
		ft_infodel(&((*info)->next));
		free((*info)->name);
		free((*info)->right);
		free((*info)->owner);
		free((*info)->group);
		free(*info);
		*info = NULL;
	}
}

void	ft_info_reverse(t_info **inf)
{
	t_info	*tmp1;
	t_info	*tmp2;

	if (*inf == NULL)
		return ;
	tmp1 = NULL;
	while ((*inf)->next != NULL)
	{
		tmp2 = (*inf)->next;
		(*inf)->next = tmp1;
		tmp1 = *inf;
		*inf = tmp2;
	}
	(*inf)->next = tmp1;
}

void	ls_choose_add_info(t_info **inf, t_info *new, unsigned char t)
{
	if (t == 0)
		ft_info_add(inf, new, &ft_infoadd_cmp);
	else
		ft_info_add(inf, new, &ft_infoadd_time);
}
