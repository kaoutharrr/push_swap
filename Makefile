# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 18:29:56 by kkouaz            #+#    #+#              #
#    Updated: 2023/02/27 02:47:29 by kkouaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS= -Wall -Wextra -Werror 
RM = rm -rf
SRC =  main.c linked_lists.c instructions.c  parsing.c push_swap.c tools.c libft/ft_atoi.c  join.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c libft/ft_strlen.c  \
	libft/ft_isdigit.c sorting.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all