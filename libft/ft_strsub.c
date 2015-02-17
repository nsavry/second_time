/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:11:14 by lsirigna          #+#    #+#             */
/*   Updated: 2013/11/23 15:44:28 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*sub;

	if (start + len > ft_strlen(s))
		return (NULL);
	sub = ft_strnew(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strncpy(sub, s + start, len);
	return (sub);
}
