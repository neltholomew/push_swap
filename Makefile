NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

LIBFT_DIR	= inc/libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= inc/printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS		= src/main.c \
			  src/parse.c \
			  src/fill_stack.c \
			  src/lists.c \
			  src/flags.c \
			  src/utils.c \
			  src/disorder.c \
			  src/chunk.c \
			  src/selection.c \
			  src/radix.c \
			  src/push.c \
			  src/swap.c \
			  src/rotate.c \
			  src/rev_rotate.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c inc/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
