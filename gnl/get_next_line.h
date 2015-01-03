/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 09:34:32 by smarie-c          #+#    #+#             */
/*   Updated: 2013/12/07 12:15:11 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF_SIZE 128

# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct		s_save
{
	int				fd;
	char			*save;
	struct s_save 	*next;
}					t_save;

int		get_next_line(int const fd, char **line);

#endif
