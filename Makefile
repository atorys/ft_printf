NAME =		libftprintf.a
HEADERS =   ft_printf.h

INCLUDES =	./

VPATH =		output \
			utils

FILES =     ft_printf.c			parsing_utils.c\
			p_char.c			printing_utils.c\
			p_int.c \
			p_unsigned.c \
			p_hex.c \
			p_upper_hex.c \
			p_pointer.c \
			p_str.c

O_FILES =	$(FILES:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g -O2

all:		$(NAME)

$(NAME):	$(O_FILES) $(HEADERS)
			ar rcs $(NAME) $?

%.o :		%.c
			gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

bonus:		all

clean:
			@rm -f $(O_FILES)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY =	all	clean fclean re bonus
