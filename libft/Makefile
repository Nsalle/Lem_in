#!bin/bash

NAME = libft.a

FILES = $(shell ls srcs | grep .c | cut -d "." -f 1)

SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))

PATH_INC = ./includes/

PATH_SRCS = ./srcs/

PATH_OBJ = ./obj/

OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))

INC = $(addprefix $(PATH_INC), libft.h)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(PATH_OBJ) $(OBJ)
			@echo "creating $(NAME)"
			@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ):
			@mkdir obj
			@echo "creating object directory"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC)
			@gcc $(FLAGS) -g -o $@ -c $< -I $(INC)

clean:
			@/bin/rm -f $(OBJ)
			@echo "deleting object files de $(NAME)"

fclean: clean
			@/bin/rm -f $(NAME)
			@echo "deleting $(NAME)"

re: fclean all

.PHONY: all clean fclean re clexec
