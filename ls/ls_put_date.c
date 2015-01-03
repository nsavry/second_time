/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:55:23 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/13 17:47:48 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ls.h"

time_t	ft_diff_date(time_t t, time_t date)
{
	time_t	diff;

	diff = t - date;
	if (diff < 0)
		return (-diff);
	return (diff);
}

void	ft_putdate(time_t date)
{
	time_t	t;

	t = time(NULL);
	if (ft_diff_date(t, date) > 15638400)
	{
		write(1, ctime(&date) + 4, 7);
		write(1, ctime(&date) + 19, 5);
	}
	else
		write(1, ctime(&date) + 4, 12);
}
