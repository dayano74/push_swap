CC := cc
CFLAGS := -Wall -Wextra -Werror
OUTPUT_OPTOIIN := -o
INCLUDE_OPTION := -I .

AR := ar rcs

SRCS := push_swap.c \
		error_print.c \
		check_args.c

OBJS :=$(SRCS:.c=.o)

NAME := push_swap.a
EXEC_NAME := push_swap

all : $(NAME) $(EXEC_NAME)

$(NAME) :$(OBJS)
		$(AR) $(NAME) $(OBJS)

$(EXEC_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OUTPUT_OPTOIIN) $(EXEC_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_OPTION) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME) $(EXEC_NAME)

re : fclean all

.PHONY : all clean fclean re
