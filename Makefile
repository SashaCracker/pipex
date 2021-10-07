NAME = pipex

BON_NAME = pipex

ALL_C = main_part/ft_split.c		main_part/ft_strjoin.c		main_part/ft_strlcpy.c \
		main_part/ft_strlen.c		main_part/ft_my_substr.c 	main_part/main.c \
		main_part/ft_strdup.c		main_part/ft_putstr.c		main_part/ft_free.c \
		main_part/ft_mistake.c		main_part/ft_path.c			main_part/ft_free_char_array.c \
		main_part/ft_pipex.c		main_part/ft_process1.c		main_part/ft_process2.c

BON_C = bonus/ft_split_bonus.c		bonus/ft_strjoin_bonus.c	bonus/ft_strlcpy_bonus.c \
        bonus/ft_strlen_bonus.c		bonus/ft_my_substr_bonus.c 	bonus/main_bonus.c \
    	bonus/ft_strdup_bonus.c		bonus/ft_putstr_bonus.c		bonus/ft_free_bonus.c \
        bonus/ft_mistake_bonus.c	bonus/ft_path_bonus.c		bonus/ft_free_char_array_bonus.c \
        bonus/ft_pipex_bonus.c		bonus/ft_process1_bonus.c	bonus/ft_process2_bonus.c

HEADER = pipex.h

BON_HEADER = pipex_bonus.h

OBJ = $(patsubst %.c,%.o,$(ALL_C))

BON_OBJ = $(patsubst %.c,%.o,$(BON_C))

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(BON_NAME): $(BON_OBJ)
	gcc $(FLAGS) $(BON_OBJ) -o $(NAME)

%.o : %.c Makefile main_part/pipex. bonus/pipex_bonus.h
	gcc $(FLAGS) -c $< -o $@

$(OBJ): $(HEADER)

$(BON_OBJ): $(BON_HEADER)

all: $(NAME)

bonus: $(BON_NAME)

clean:
		rm -f $(OBJ) $(BON_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re