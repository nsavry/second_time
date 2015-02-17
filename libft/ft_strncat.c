/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:45:55 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/07 03:37:34 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	while (s1[j])
		j++;
	while (i < n && s2[i])
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (s1);
}
