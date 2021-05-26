cmake_minimum_required(VERSION 3.17)
project(printf C)

set(CMAKE_C_STANDARD 99)

include_directories(./)

add_executable(printf
        main.c
        ft_printf.c
        ft_printf.h
        output/p_char.c
        output/p_int.c
        utils/parsing_utils.c
        utils/printing_utils.c
        output/p_unsigned.c
        output/p_hex.c
        output/p_upper_hex.c
        output/p_str.c
        output/p_pointer.c
        output/p_nvalues_bonus.c)
