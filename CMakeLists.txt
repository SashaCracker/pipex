cmake_minimum_required(VERSION 3.19)
project(pipex C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pipex
        main_part/pipex.h
        pipex.h
        main_part/ft_split.c
        main_part/ft_strjoin.c
        main_part/ft_strlcpy.c
        main_part/ft_strlen.c
        main_part/ft_strdup.c
        main_part/ft_my_substr.c
        main_part/ft_putstr.c
        main_part/ft_free_char_array.c
        main_part/main.c
        main_part/ft_path.c
        main_part/ft_free.c
        main_part/ft_pipex.c
        main_part/ft_process1.c
        main_part/ft_process2.c
        main_part/ft_mistake.c
        bonus/pipex_bonus.h
        bonus/main_bonus.c
        bonus/ft_free_bonus.c
        bonus/ft_free_char_array_bonus.c
        bonus/ft_mistake_bonus.c
        bonus/ft_path_bonus.c
        bonus/ft_process1_bonus.c
        bonus/ft_process2_bonus.c
        bonus/ft_my_substr_bonus.c
        bonus/ft_pipex_bonus.c
        bonus/ft_putstr_bonus.c
        bonus/ft_split_bonus.c
        bonus/ft_strdup_bonus.c
        bonus/ft_strjoin_bonus.c
        bonus/ft_strlcpy_bonus.c
        bonus/ft_strlen_bonus.c
        )
