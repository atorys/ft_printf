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

FILES_BONUS = p_nvalues_bonus.c

O_FILES =		$(FILES:.c=.o)
O_FILES_BONUS =	$(FILES_BONUS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g -O2

all:		$(NAME)

$(NAME):	$(O_FILES) $(HEADERS)
			ar rcs $(NAME) $?

bonus:		$(O_FILES) $(O_FILES_BONUS) $(HEADERS)
			ar rcs $(NAME) $?

%.o :		%.c
			gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
			@rm -f $(O_FILES) $(O_FILES_BONUS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY =	all	clean fclean re bonus
