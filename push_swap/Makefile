# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 16:28:31 by wsaturn           #+#    #+#              #
#    Updated: 2021/12/14 16:28:35 by wsaturn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FILES	= 	push_swap.c		ft_split.c		ft_atoi.c\
			com1.c			com2.c			com3.c\
			ft_strcmp.c		check_error.c	errors.c\
			create_node.c	sort_small.c	utils.c\
			sort.c			sort_bit.c

HEADER	=	push_swap.h
OBJ		=	$(patsubst %.c, %.o, $(FILES))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)
AR		=	ar rcs
RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(MAKE) -C libftprintf
	$(CC) $(OBJ) $(CFLAGS) libftprintf/libftprintf.a -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@$(MAKE) clean -C libftprintf
	@rm -f $(OBJ)

fclean	:	clean
	@$(MAKE) fclean -C libftprintf
	@$(RM) $(NAME)

re		:	fclean all
