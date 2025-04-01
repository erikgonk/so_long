# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 19:36:23 by erigonza          #+#    #+#              #
#    Updated: 2025/04/01 11:55:54 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 

INCLUDES = -I ./inc/\
           -I ./src/libft/\
		   -I ./mlx/
SRC =  main.c valid_map.c img.c zero.c movement.c print_img.c \
			floodfill.c extra.c \
			ghosts.c

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))


all: dir $(NAME)

-include $(DEP)
dir:
	make -C ./mlx/ --no-print-directory
	make -C ./src/libft/ --no-print-directory
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)
$(NAME): $(OBJ) ./src/libft/libft.a
	$(CC) $(FLAGS) $(OBJ) ./mlx/libmlx.a -lXext -lX11 -lm -lz ./src/libft/libft.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"
clean:
	rm -rf $(DIR_OBJ)
	make clean -C ./src/libft/ --no-print-directory 
	echo "DEPENDENCIES Erased :D"
f fclean: clean
	rm -rf $(NAME)
	make fclean -C ./src/libft/ --no-print-directory 
	echo "EVERYTHING Erased D:"

re: fclean all

r run: all
	./$(NAME) maps/classic.ber

.PHONY: f fclean all clean re dir r run
.SILENT:
