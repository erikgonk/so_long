# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/04/03 13:23:02 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;93m
WHITE = \033[1m
CLEAR_SCREEN = \x1b[1J \x1b[H

#-----------------------------------VARIABLES----------------------------------#

NAME = so_long

MLX = mlx/
MLX_A = $(addprefix $(MLX), libmlx.a)


FTPRINTF = src/printf/
FTPRINTF_A = $(addprefix $(FTPRINTF), libftprintf.a)

SRC_NAMES = main.c valid_map.c img.c zero.c movement.c \
			get_next_line.c get_next_line_utils.c \

SRCS = $(addprefix src/, $(SRC_NAMES))
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LDFLAGS = -L$(FTPRINTF) -L$(MLX)
LDLIBS = -lftprintf -lmlx -framework OpenGL -framework AppKit

RM = rm -fr

#------------------------------------EXECUTE-----------------------------------#

all: $(MLX_A) $(NAME)

$(MLX_A):
	make -C $(FTPRINTF) --no-print-directory
	make -C $(MLX) --no-print-directory

$(NAME): $(OBJS) $(MLX_A) $(FTPRINTF_A)
	$(CC) $(CFLAGS) -Imlx -Iinc -Isrc/printf $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

$(OBJS): %.o: %.c Makefile
	$(CC) $(CFLAGS) -Imlx -Iinc -Isrc/printf -MMD -MP -c -o $@ $<
	echo -n "$(CLEAR_SCREEN)"
#	echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
#	echo "\t\t\t\t\t\t\t\t\t\t\t$(YELLOW)READY TO PLAY!!"
#	echo "\t\t\t\t\t\t\t\t\t\t\t    👾🟡👻"
#	echo "$(WHITE)"
#	echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

#-------------------------------------CLEAN------------------------------------#

clean:
	$(RM) $(OBJS) $(DEPS) --no-print-directory
	make clean -C $(MLX) --no-print-directory
	make clean -C $(FTPRINTF) --no-print-directory

fclean: clean
	$(RM) $(NAME) --no-print-directory
	make fclean -C $(FTPRINTF) --no-print-directory
	make clean -C $(MLX) --no-print-directory
	rm -fr *.dSYM --no-print-directory

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
