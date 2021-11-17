# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 15:40:01 by wsaturn           #+#    #+#              #
#    Updated: 2021/10/30 20:44:01 by wsaturn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c		ft_func.c	ft_func2.c	ft_process.c
HEADER	=	ft_printf.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			ar rcs $(NAME) $?

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
