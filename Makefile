# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 14:59:43 by seungryk          #+#    #+#              #
#    Updated: 2024/03/19 08:07:23 by seungryk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -Llibft -lft
SRCS = main.c ft_init.c ft_preprocess.c ft_utils.c ft_greedy.c \
		ft_function.c ft_function2.c ft_small_stack.c ft_sort_stack.c \
		ft_error.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_push_swap.h
SRCS_B = bonus/main_bonus.c bonus/ft_checker_bonus.c \
		bonus/ft_preprocess_bonus.c bonus/ft_error_bonus.c \
		bonus/ft_function_bonus.c bonus/ft_function2_bonus.c \
		bonus/ft_greedy_bonus.c bonus/ft_init_bonus.c \
		bonus/ft_small_stack_bonus.c bonus/ft_sort_stack_bonus.c \
		bonus/ft_utils_bonus.c
OBJS_B = $(SRCS_B:.c=.o)
HEADER_B = ft_checker_bonus.h
PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(OBJS))
CHECKER = $(addprefix $(OBJ_DIR)/, $(OBJS_B))
NAME = push_swap
NAME_B = checker
OBJ_DIR = obj

all : $(NAME)

$(NAME) : $(PUSH_SWAP) make_mandatory

bonus : $(CHECKER) make_bonus

make_mandatory : $(PUSH_SWAP)
	make -C ./libft
	$(CC) $(CFLAGS) $(PUSH_SWAP) -o $(NAME) $(LIBFT)
	@touch $@

make_bonus : $(CHECKER)
	make -C ./libft bonus
	$(CC) $(CFLAGS) $(CHECKER) -o $(NAME_B) $(LIBFT)
	@touch $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/bonus

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean : 
	make -C ./libft clean
	@rm -f make_mandatory make_bonus
	@rm -rf $(OBJ_DIR)

fclean : clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
	rm -f $(NAME_B)

re : 
	make fclean
	make all

.PHONY: all clean fclean re bonus

