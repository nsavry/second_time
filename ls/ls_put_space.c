/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:46:58 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/13 11:54:58 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

void	ft_put_space_before(unsigned char len, char *str)
{
	unsigned char	t;

	ft_putchar(' ');
	t = 0;
	if (len > (unsigned char) ft_strlen(str))
		t = len - (unsigned char) ft_strlen(str);
	while (t > 0)
	{
		ft_putchar(' ');
		t--;
	}
	ft_putstr(str);
}

void	ft_put_space_after(unsigned char len, char *str)
{
	unsigned char	t;

	ft_putchar(' ');
	ft_putstr(str);
	t = 0;
	if (len > (unsigned char) ft_strlen(str))
		t = len - (unsigned char) ft_strlen(str);
	while (t > 0)
	{
		ft_putchar(' ');
		t--;
	}
}
