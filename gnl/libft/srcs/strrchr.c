/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:05:51 by lsirigna          #+#    #+#             */
/*   Updated: 2013/11/23 19:31:06 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	int		i;

	i = 0;
	while (s[i])
		i++;
	letter = (char)c;
	while (i && s[i] != letter)
	{
		i--;
	}
	if (s[i] == letter)
		return ((char *)s + i);
	return (0);
}
