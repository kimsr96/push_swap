CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = -Llibft -lft
SRCS = main.c ft_preprocess.c ft_preprocess2.c ft_function.c ft_utils.c \
		ft_small_stack.c ft_sort_stack.c
OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
NAME = push_swap
OBJ_DIR = obj

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $(OBJS_FILES) $(LIBFT)

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean : 
	make -C ./libft clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re