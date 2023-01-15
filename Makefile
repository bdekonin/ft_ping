NAME		= ft_ping
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCS	=	-I./inc

SRC_DIR		= ./src/

SRCS		=	$(SRC_DIR)main.c \
				$(SRC_DIR)parser.c \
				$(SRC_DIR)printer.c \

OBJS		= $(SRCS:.c=.o)

FT_DIR	=	./libft/
FT_MAKE	=	$(MAKE) -C $(FT_DIR)
FT_LIB		= -L$(FT_DIR) -lft

GREEN = \033[92m
NOCOLOR = \033[0;38m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GREEN)[ping] - Compiling $(NAME)..$(NOCOLOR)"
	@$(FT_MAKE)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(FT_LIB)

.c.o:
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	$(FT_MAKE) clean
	@echo "$(GREEN)[ping] - Running clean..$(NOCOLOR)"
	@echo "$(GREEN)[ping] - Removing object files..$(NOCOLOR)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)[ping] - Finished running clean!$(NOCOLOR)"

fclean:
	@$(FT_MAKE) fclean
	@echo "$(GREEN)[ping] - Running fclean..$(NOCOLOR)"
	@echo "$(GREEN)[ping] - Removing object files..$(NOCOLOR)"
	@echo "$(GREEN)[ping] - Finished running fclean!$(NOCOLOR)"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re