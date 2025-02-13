CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = pipex
BNAME = pipex_bonus

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
RESET = \033[0m

SRCS =	./my_library/libft/ft_atoi.c ./my_library/libft/ft_bzero.c ./my_library/libft/ft_calloc.c ./my_library/libft/ft_isalnum.c ./my_library/libft/ft_isalpha.c ./my_library/libft/ft_isascii.c ./my_library/libft/ft_isdigit.c ./my_library/libft/ft_isprint.c ./my_library/libft/ft_itoa.c ./my_library/libft/ft_lstadd_back_bonus.c ./my_library/libft/ft_lstadd_front_bonus.c ./my_library/libft/ft_lstclear_bonus.c ./my_library/libft/ft_lstdelone_bonus.c ./my_library/libft/ft_lstiter_bonus.c ./my_library/libft/ft_lstlast_bonus.c ./my_library/libft/ft_lstmap_bonus.c ./my_library/libft/ft_lstnew_bonus.c ./my_library/libft/ft_lstsize_bonus.c ./my_library/libft/ft_memchr.c ./my_library/libft/ft_memcmp.c ./my_library/libft/ft_memcpy.c ./my_library/libft/ft_memmove.c ./my_library/libft/ft_memset.c ./my_library/libft/ft_putchar_fd.c ./my_library/libft/ft_putendl_fd.c ./my_library/libft/ft_putnbr_fd.c ./my_library/libft/ft_putstr_fd.c ./my_library/libft/ft_split.c ./my_library/libft/ft_strchr.c ./my_library/libft/ft_strdup.c ./my_library/libft/ft_striteri.c ./my_library/libft/ft_strjoin.c ./my_library/libft/ft_strlcat.c ./my_library/libft/ft_strlcpy.c ./my_library/libft/ft_strlen.c ./my_library/libft/ft_strmapi.c ./my_library/libft/ft_strncmp.c ./my_library/libft/ft_strnstr.c ./my_library/libft/ft_strrchr.c ./my_library/libft/ft_strtrim.c ./my_library/libft/ft_substr.c ./my_library/libft/ft_tolower.c ./my_library/libft/ft_toupper.c ./my_library/ft_printf/ft_nb_count.c ./my_library/ft_printf/ft_printf.c ./my_library/ft_printf/ft_putadrr.c ./my_library/ft_printf/ft_putchar.c ./my_library/ft_printf/ft_puthexa.c ./my_library/ft_printf/ft_putnbr.c ./my_library/ft_printf/ft_putstr.c ./my_library/ft_printf/ft_putunint.c ./my_library/get_next_line/get_next_line.c ./my_library/perror/ft_perror.c error_handling.c find_path.c main.c pipex.c

BONUS =	./my_library/libft/ft_atoi.c ./my_library/libft/ft_bzero.c ./my_library/libft/ft_calloc.c ./my_library/libft/ft_isalnum.c ./my_library/libft/ft_isalpha.c ./my_library/libft/ft_isascii.c ./my_library/libft/ft_isdigit.c ./my_library/libft/ft_isprint.c ./my_library/libft/ft_itoa.c ./my_library/libft/ft_lstadd_back_bonus.c ./my_library/libft/ft_lstadd_front_bonus.c ./my_library/libft/ft_lstclear_bonus.c ./my_library/libft/ft_lstdelone_bonus.c ./my_library/libft/ft_lstiter_bonus.c ./my_library/libft/ft_lstlast_bonus.c ./my_library/libft/ft_lstmap_bonus.c ./my_library/libft/ft_lstnew_bonus.c ./my_library/libft/ft_lstsize_bonus.c ./my_library/libft/ft_memchr.c ./my_library/libft/ft_memcmp.c ./my_library/libft/ft_memcpy.c ./my_library/libft/ft_memmove.c ./my_library/libft/ft_memset.c ./my_library/libft/ft_putchar_fd.c ./my_library/libft/ft_putendl_fd.c ./my_library/libft/ft_putnbr_fd.c ./my_library/libft/ft_putstr_fd.c ./my_library/libft/ft_split.c ./my_library/libft/ft_strchr.c ./my_library/libft/ft_strdup.c ./my_library/libft/ft_striteri.c ./my_library/libft/ft_strjoin.c ./my_library/libft/ft_strlcat.c ./my_library/libft/ft_strlcpy.c ./my_library/libft/ft_strlen.c ./my_library/libft/ft_strmapi.c ./my_library/libft/ft_strncmp.c ./my_library/libft/ft_strnstr.c ./my_library/libft/ft_strrchr.c ./my_library/libft/ft_strtrim.c ./my_library/libft/ft_substr.c ./my_library/libft/ft_tolower.c ./my_library/libft/ft_toupper.c ./my_library/ft_printf/ft_nb_count.c ./my_library/ft_printf/ft_printf.c ./my_library/ft_printf/ft_putadrr.c ./my_library/ft_printf/ft_putchar.c ./my_library/ft_printf/ft_puthexa.c ./my_library/ft_printf/ft_putnbr.c ./my_library/ft_printf/ft_putstr.c ./my_library/ft_printf/ft_putunint.c ./my_library/get_next_line/get_next_line.c ./my_library/perror/ft_perror.c error_handling.c find_path.c main_bonus.c pipex.c here_doc_bonus.c utils_bonus.c

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@echo "$(BLUE)Compiling Pipex program$(RESET)"
	@echo "$(BLUE)➜ libft$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ ft_printf$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ ft_perror$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ get_next_line$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ main and other utility files$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ creating pipex program$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@$(CC) $(FLAGS) $(OFILES) -o $(NAME)
	@echo "$(GREEN)pipex compiled successfully!$(RESET)"
	@sleep 0.3; echo "$(PURPLE)Created by: fatheddine-bicane$(RESET)"


bonus: $(BNAME)

$(BNAME): $(BOFILES)
	@echo "$(BLUE)Compiling Pipex bonus program$(RESET)"
	@echo "$(BLUE)➜ libft$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ ft_printf$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ ft_perror$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ get_next_line$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ main bonus and other utility bonus files$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@echo "$(BLUE)➜ creating pipex bonus program$(RESET)\c"
	@sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"; sleep 0.3; echo "$(BLUE).$(RESET)\c"
	@sleep 0.3; echo "$(BLUE)✓$(RESET)"
	@$(CC) $(FLAGS) $(BOFILES) -o $(BNAME)
	@echo "$(GREEN)pipex bonus compiled successfully!$(RESET)"
	@sleep 0.3; echo "$(PURPLE)Created by: fatheddine-bicane$(RESET)"

clean:
	@rm -f $(OFILES) $(BOFILES)
	@echo "$(YELLOW)Cleaning object files$(RESET)\c"
	@sleep 0.3; echo "$(YELLOW).$(RESET)\c"; sleep 0.3; echo "$(YELLOW).$(RESET)\c"; sleep 0.3; echo "$(YELLOW).$(RESET)\c"
	@sleep 0.3; echo "$(YELLOW)✓$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "$(YELLOW)Cleaning executables$(RESET)\c"
	@sleep 0.3; echo "$(YELLOW).$(RESET)\c"; sleep 0.3; echo "$(YELLOW).$(RESET)\c"; sleep 0.3; echo "$(YELLOW).$(RESET)\c"
	@sleep 0.3; echo "$(YELLOW)✓$(RESET)"

re: fclean all

re_bonus : fclean bonus

.PHONY: all bonus clean fclean re
