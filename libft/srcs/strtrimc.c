/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrimc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 18:34:43 by lsirigna          #+#    #+#             */
/*   Updated: 2014/02/18 04:02:39 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strtrimc(char **s, char c)
{
	size_t		start;
	size_t		end;
	char		*tmp;

	start = 0;
	while ((*s)[start] && (*s)[start] == c)
		start++;
	end = ft_strlen(*s);
	if (start == end)
	{
		free(*s);
		*s = ft_strdup("");
	}
	else
	{
		end--;
		while (end && (*s)[end] == c)
			end--;
		end++;
		tmp = ft_strsub(*s, start, end - start);
		*s = tmp;
	}
}
