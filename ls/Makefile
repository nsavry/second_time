#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:31:01 by smarie-c          #+#    #+#              #
#    Updated: 2013/12/13 18:59:09 by smarie-c         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = ft_ls

SRC = ft_ls.c ls_add_info.c ls_dir.c ls_error.c ls_files.c ls_find.c \
	ls_get_info.c ls_info.c ls_main.c ls_options.c ls_put_date.c \
	ls_put_info.c ls_put_space.c ls_tool.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIB = ./libft

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c $(FLAGS) $(SRC) -I$(LIB)
	gcc -o $(NAME) $(OBJ) -L$(LIB) -lft

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
