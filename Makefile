# Compiler and flags
CC = gcc
CFLAGS =

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard ./*.c)
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

# Program name
NAME = push_swap

# Default rule to build the default target - the variables are its dependencies which must be build befor anything else
# if not yet build the Make program will move to find the dependencies and build them one by one
all: $(LIBFT) $(NAME)

# Compilation process - 2st stage of the build process - build obj. files
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the executable - last step - linking process
#-Iinclude -ldl -lglfw -pthread -lm
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Libft build process - call makefile to build a static Libft library
$(LIBFT):
	make -C $(LIBFT_DIR)
	
# Clean rule
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Full clean rule
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re
