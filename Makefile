# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 18:29:56 by kkouaz            #+#    #+#              #
#    Updated: 2023/03/06 12:43:43 by kkouaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
CC = cc
CFLAGS= -Wall -Wextra -Werror 
RM = rm -rf
SRC =  main.c linked_lists.c instructions.c  parsing.c push_swap.c tools.c libft/ft_atoi.c  join.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c libft/ft_strlen.c  \
	libft/ft_isdigit.c sorting.c norm.c
SRC_B =  checker.c  linked_lists.c instructions.c  parsing.c push_swap.c tools.c libft/ft_atoi.c  join.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c libft/ft_strlen.c  \
	 tools_bonus.c libft/ft_isdigit.c sorting.c norm.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_B =$(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	
bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
	 $(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B)
clean : 
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all
