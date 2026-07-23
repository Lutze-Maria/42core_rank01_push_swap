


# 1. Variables
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

RM          = rm -f
HEADER		= push_swap.h
LIBFT 		= ./libft/libft.a
PRINTF 		= ./ft_printf/libftprintf.a
INCLUDES 	= -I. -Ilibft -Iparsing -Ibuild_stack

# 2. Source Files
SRCS        = 	main.c \
				parsing/ft_split.c parsing/parse_input.c \
				build_stack/stack_init.c build_stack/stack_utils.c \
				build_stack/stack_error_checks.c build_stack/stack_free.c \
				commands/command_push.c commands/command_reverse_rot.c \
				commands/command_rotate.c commands/command_swap.c \
				sorting/selection-sort.c  sorting/bucket-sort.c\
				sorting/adaptive.c build_stack/test_stack.c\
				sorting/utils.c\
				print_container.c



# 3. Object Files
# replaces the .c extension with .o
OBJS        = $(SRCS:.c=.o)


# 4. Mandatory Rules
all: $(NAME)

$(NAME): mlibft mprintf $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

mlibft:
	$(MAKE) -C libft

mprintf:
	$(MAKE) -C ft_printf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all


# 5. Phony Targets
# prevents make from confusing these rules with files of the same name
.PHONY: all clean fclean re libft
