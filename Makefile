NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f
SRCS = \
./ft_printf.c \
./ft_printf_utils1.c \
./ft_printf_utils2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re