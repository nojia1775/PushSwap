CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
       src/verif_param.c \
       src/add_list.c \
       src/ft_free.c \
       src/len.c \
       src/push.c \
       src/swap.c \
       src/rotate.c \
       src/rrotate.c \
       src/change_index.c \
       src/algo.c  \
       src/utils1.c \
       src/trois.c \
       src/dep.c \
       src/algo2b.c \
       src/utils2.c \
       src/algo2b.c \
       src/depb.c \
       src/exp.c \
       src/calibrage.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

$(NAME): $(OBJS)
	@make -C FT_PRINTF
	@make -C LIBFT
	$(CC) $(CFLAGS) $^ -o $@ LIBFT/libft.a FT_PRINTF/libftprintf.a

all: $(NAME)

clean:
	rm -f $(OBJS)
	@make clean -C FT_PRINTF
	@make clean -C LIBFT

fclean: clean
	rm -f $(NAME)
	@make fclean -C FT_PRINTF
	@make fclean -C LIBFT

re: fclean all

.PHONY: all clean fclean re
