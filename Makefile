# Compiler and flags
CC	= cc
CFLAGS = -Wall -Wextra -Werror -g

# Project name
NAME = pipex

# Directories
LIBFT_DIR = my_library/libft
PRINTF_DIR = my_library/ft_printf
GNL_DIR = my_library/get_next_line
PERROR_DIR = my_library/perror
LIB_DIRS = $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR) $(PERROR_DIR)

# Source files
SRCS = pipex.c find_path.c main_function_2.c error_handling.c pipex.c
OBJS = $(SRCS:.c=.o)

# Library source files (using wildcard to get all .c files in each directory)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/*.c)
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
PERROR_SRCS = $(wildcard $(PERROR_DIR)/*.c)

# Library objects
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
PERROR_OBJS = $(PERROR_SRCS:.c=.o)
LIB_OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS) $(PERROR_OBJS)

# Include paths
INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(PERROR_DIR) -Imy_library

# Main target
all: $(NAME)

# Linking
$(NAME): $(OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) -o $(NAME)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean objects
clean:
	rm -f $(OBJS)
	rm -f $(LIB_OBJS)

# Clean objects and executable
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re
