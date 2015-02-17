/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 23:07:37 by lsirigna          #+#    #+#             */
/*   Updated: 2014/03/22 23:07:40 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_printlst(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstaddend(t_list **alst, char *buff)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = (t_list *)malloc(sizeof(t_list));
	tmp2->content = ft_strdup(buff);
	tmp2->next = NULL;
	if (!tmp)
		*alst = tmp2;
	else
		tmp->next = tmp2;
}
