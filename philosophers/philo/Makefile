# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 13:24:01 by wsaturn           #+#    #+#              #
#    Updated: 2022/01/03 13:24:03 by wsaturn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main.c\
			ft_atoi.c\
			ft_init.c\
			ft_threads.c\
			ft_utils.c\

HEADER	=	philo.h
OBJ		=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)
PTFLAGS	=	-g -pthread

all		:	$(NAME)

.PHONY	:	all, re, clean, fclean, $(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(PTFLAGS) -o $(NAME) $(OBJ)

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) $(PTFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all
