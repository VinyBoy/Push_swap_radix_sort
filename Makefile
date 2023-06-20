# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viny <viny@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 16:28:31 by viny              #+#    #+#              #
#    Updated: 2023/06/13 11:18:46 by viny             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								    CONFIG									   #
################################################################################

NAME	=	push_swap

INC_DIR	=	./include/

CC	=	cc 

CFLAGS	=	-g -Wall -Wextra -Werror -I$(INC_DIR)

RM	=	rm -rf

AUTHOR	=	vnieto-j

LDFLAGS	=	-Llibft/Libft -lft

################################################################################
#                                 PROGRAM'S SRCSS                               #
################################################################################


SRC_DIR =	./src/

# On attribuer a la variable SRCS tout les fichier .c dans ./src

SRCS =	$(wildcard $(SRC_DIR)*.c)

# Tranforme les fichiers .c en .o dans chaque fichier de SRCS

OBJS =	$(patsubst %.c, %.o, $(SRCS))

################################################################################
#                             		 NAME                                      #
################################################################################

$(NAME): $(OBJS) $(INC_DIR)push_swap.h
	@make -C ./libft/Libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

all : $(NAME)

clean :
		make -C libft/Libft clean
		$(RM) $(OBJS)

fclean : clean
		@make -C libft/Libft fclean
		@$(RM) $(NAME) $(OBJS)

re : 
		make -C libft/Libft re
		make fclean
		make all

.PHONY: all clean fclean re