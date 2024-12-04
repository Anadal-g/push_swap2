# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 10:42:37 by camarcos          #+#    #+#              #
#    Updated: 2024/12/03 14:57:14 by carolinamc       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAMES
NAME = push_swap

# LIBFT
LIBFT = libft/libft.a

VPATH = src:src/movements:src/stack

# SOURCE FILES
SRC		= 	swap.c push.c rotate.c reverse_rotate.c \
					utils.c create_free.c arguments.c main.c pruebas.c \

# OBJECT FILES
OBJ_FILES 		= $(SRC:.c=.o)

# COMPILER OPTIONS 
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3
INCLUDE = -I includes
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)
$(NAME):	$(OBJ_FILES)
	@make -sC libft
	@echo "$(PINK)Compiling the PUSH_SWAP program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) $(INCLUDE) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	@echo "$(PINK)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)  
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re

t: all
	@cp $(NAME) tester/
	@cd tester; bash push_swap_test_linux.sh 50 50