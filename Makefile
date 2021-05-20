NAME =		libftprintf.a
HEADERS =   ft_printf.h

FILES =     ft_printf.c \
			p_char.c \
			p_str.c \
			p_int.c \
			p_pointer.c \
			p_un_int.c \
			p_hex.c \
			p_upp_hex.c \

O_FILES =	$(FILES:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g -O2

all:		$(NAME)

$(NAME):	$(O_FILES) $(HEADERS)
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			ar rcs $(NAME) libft.a $?

%.o :		%.c
			gcc $(CFLAGS) -c $< -o $@ -MMD

clean:
			@rm -f $(O_FILES)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: 	all	clean fclean re
