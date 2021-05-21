cmake_minimum_required(VERSION 3.17)
project(printf C)

set(CMAKE_C_STANDARD 99)

include_directories(./)

add_executable(printf
        main.c
        ft_printf.c
        libft/ft_isdigit.c
        libft/ft_putchar_fd.c
        ft_printf.h
        libft/ft_strlen.c
        p_char.c p_int.c)
