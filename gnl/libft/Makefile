#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:57:53 by lsirigna          #+#    #+#              #
#    Updated: 2014/01/24 20:36:21 by lsirigna         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = ft
INCLUDE = includes/
SRCPATH = ./srcs/
CFLAGS = -O3 -Wall -Werror -Wextra
C = \033[1;34m
SRCS = \
	   atoi.c\
	   bzero.c\
	   isalnum.c\
	   isalpha.c\
	   isascii.c\
	   isdigit.c\
	   isprint.c\
	   itoa.c\
	   lstadd.c\
	   lstdel.c\
	   lstdelone.c\
	   lstiter.c\
	   lstmap.c\
	   lstnew.c\
	   memalloc.c\
	   memccpy.c\
	   memchr.c\
	   memcmp.c\
	   memcpy.c\
	   memdel.c\
	   memmove.c\
	   memset.c\
	   putchar.c\
	   putchar_fd.c\
	   putendl.c\
	   putendl_fd.c\
	   putnbr.c\
	   putnbr_fd.c\
	   putstr.c\
	   putstr_fd.c\
	   strcat.c\
	   strchr.c\
	   strclr.c\
	   strcmp.c\
	   strcpy.c\
	   strdel.c\
	   strdup.c\
	   strequ.c\
	   striter.c\
	   striteri.c\
	   strjoin.c\
	   strlcat.c\
	   strlen.c\
	   strmap.c\
	   strmapi.c\
	   strncat.c\
	   strncmp.c\
	   strncpy.c\
	   strnequ.c\
	   strnew.c\
	   strnstr.c\
	   strrchr.c\
	   strsplit.c\
	   strstr.c\
	   strsub.c\
	   strtrim.c\
	   tolower.c\
	   toupper.c\
	   gnl.c\
	   strtrim.c

NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.c=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
