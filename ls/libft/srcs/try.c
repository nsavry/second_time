#include "libft.h"

void	ft_del(void **p)
{
	if (*p != NULL)
		ft_memdel(p);
}

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstdel_mem(t_list **lst)
{
	ft_lstdel(lst, &ft_memdel_size);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}

void	ft_lst_add(t_list **lst, t_list *new, void (*f)(t_list **, t_list *))
{
	if (*lst == NULL)
		*lst = new;
	else
		f(lst, new);
}

void	ft_lstadd_cmp(t_list **lst, t_list *new)
{
	t_list		*tmp1;
	t_list		*tmp2;
	size_t		min;

	tmp1 = *lst;
	min = ft_min(tmp1->content_size, new->content_size);
	if (ft_memcmp(new->content, tmp1->content, min) < 0)
	{
		ft_lstadd(lst, new);
		return ;
	}
	tmp2 = tmp1->next;
	while (tmp2 != NULL)
	{
		min = ft_min(tmp2->content_size, new->content_size);
		if (ft_memcmp(new->content, tmp2->content, min) < 0)
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

size_t		ft_min(size_t size1, size_t size2)
{
	if (size1 < size2)
		return (size1);
	return (size2);
}

void	ft_memdel_size(void *content, size_t size)
{
	if (size != 0)
		ft_memdel(&content);
}

size_t		ft_max(size_t size1, size_t size2)
{
	if (size1 < size2)
		return (size2);
	return (size1);
}