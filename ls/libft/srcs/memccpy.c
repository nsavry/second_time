/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 23:07:37 by lsirigna          #+#    #+#             */
/*   Updated: 2014/03/22 23:07:40 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char			*tmp_s1;
	const unsigned char		*tmp_s2;
	unsigned int			i;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	while (i < n && (*(tmp_s2 + i) != (unsigned char)c))
	{
		*(tmp_s1 + i) = *(tmp_s2 + i);
		i++;
	}
	if (i != n)
	{
		tmp_s1[i] = (unsigned char)c;
		return (s1 + i + 1);
	}
	else if (*(tmp_s1 + i) == (unsigned char)c)
	{
		tmp_s1[i] = (unsigned char)c;
		return (s1 + i);
	}
	else
		return (NULL);
}
