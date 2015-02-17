/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_rcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 13:07:49 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/01 16:01:18 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_rcmp(t_list **lst, t_list *new)
{
	t_list		*tmp1;
	t_list		*tmp2;
	size_t		min;

	tmp1 = *lst;
	min = ft_min(tmp1->content_size, new->content_size);
	if (ft_memcmp(new->content, tmp1->content, min) > 0)
	{
		ft_lstadd(lst, new);
		return ;
	}
	tmp2 = tmp1->next;
	while (tmp2 != NULL)
	{
		min = ft_min(tmp2->content_size, new->content_size);
		if (ft_memcmp(new->content, tmp2->content, min) > 0)
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
