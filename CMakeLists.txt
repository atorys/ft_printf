cmake_minimum_required(VERSION 3.17)
project(printf C)

set(CMAKE_C_STANDARD 99)

include_directories(./)

add_executable(printf
        main.c
        ft_printf.c
        ft_printf.h
        p_char.c
        p_int.c
        parsing_utils.c
        printing_utils.c
        p_unsigned.c p_hex.c)
