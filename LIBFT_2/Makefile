# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 20:38:40 by wsaturn           #+#    #+#              #
#    Updated: 2021/10/18 21:21:07 by wsaturn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c		ft_isalpha.c	ft_substr.c		ft_putchar_fd.c\
			ft_memcpy.c		ft_strdup.c		ft_strjoin.c	ft_putstr_fd.c\
			ft_tolower.c	ft_bzero.c		ft_strtrim.c	ft_putendl_fd.c\
			ft_isascii.c	ft_memmove.c	ft_split.c		ft_putnbr_fd.c\
			ft_strlcat.c	ft_strncmp.c	ft_itoa.c\
			ft_toupper.c	ft_calloc.c		ft_isdigit.c\
			ft_memchr.c		ft_memset.c		ft_strmapi.c\
			ft_strlcpy.c	ft_strnstr.c	ft_isalnum.c\
			ft_isprint.c	ft_memcmp.c		ft_striteri.c\
			ft_strchr.c		ft_strlen.c		ft_strrchr.c\

SRCS_B	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

HEADER	=	libft.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))
OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar -rcs $(NAME) $?

%.o		: 	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus	:
	make OBJ="$(OBJ_B)"

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all
