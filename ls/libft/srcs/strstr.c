/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:10:56 by lsirigna          #+#    #+#             */
/*   Updated: 2013/11/23 13:43:37 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (!s2[i])
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			k = i;
			j = 0;
			while (s2[j] && s1[k] == s2[j])
			{
				k++;
				j++;
			}
			if (!s2[j])
				return ((char*)s1 + i);
		}
		i++;
	}
	return (0);
}
