NAME =		libftprintf.a
HEADERS =

FILES =
O_FILES =	$(FILES:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g -O2

all:		$(NAME)

$(NAME):	$(O_FILES) $(HEADERS)
			ar rcs $(NAME) $?

%.o :		%.c
			gcc $(CFLAGS) -c $< -o $@ -MMD

clean:
			@rm -f $(O_FILES)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all


.PHONY: 	all	clean fclean re
