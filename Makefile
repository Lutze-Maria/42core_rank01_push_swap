


# 1. Variables
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

RM          = rm -f
HEADER		= push_swap.h
LIBFT 		= ./libft/libft.a
INCLUDES 	= -I. -Ilibft -Iparsing -Ibuild_stack

# 2. Source Files
SRCS        = 	main.c \
				parsing/ft_split.c parsing/parse_input.c \
				build_stack/stack_init.c build_stack/stack_utils.c \
				build_stack/stack_error_checks.c build_stack/stack_free.c \
				command/command_push.c command/command_reverse_rotate.c \
				command/command_rotate.c command/command_swap.c \
				build_stack/test_stack.c


# 3. Object Files
# replaces the .c extension with .o
OBJS        = $(SRCS:.c=.o)


# 4. Mandatory Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all


# 5. Phony Targets
# prevents make from confusing these rules with files of the same name
.PHONY: all clean fclean re
