# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/05/10 14:03:04 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;93m
WHITE = \033[1m
CLEAR_SCREEN = \x1b[1J \x1b[H

#-----------------------------------VARIABLES----------------------------------#

NAME = so_long

MLX = mlx/
MLX_A = $(addprefix $(MLX), libmlx.a)


LIBFT = src/libft/
LIBFT_A = $(addprefix $(LIBFT), libft.a)

SRC_NAMES = main.c valid_map.c img.c zero.c movement.c print_img.c \
			floodfill.c extra.c

SRCS = $(addprefix src/, $(SRC_NAMES))
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LDFLAGS = -L$(LIBFT) -L$(MLX)
LDLIBS = $(LIBFT_A) -lmlx -framework OpenGL -framework AppKit

RM = rm -fr

#------------------------------------EXECUTE-----------------------------------#

all: libft $(MLX_A) $(NAME)

$(MLX_A):
	make -C $(MLX) --no-print-directory

$(NAME): $(OBJS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) -Imlx -Iinc -I$(LIBFT) $(LDFLAGS) $(LDLIBS) $(SRCS) -o $(NAME)

$(OBJS): %.o: %.c Makefile
	$(CC) $(CFLAGS) -Imlx -Iinc -I$(LIBFT) -MMD -MP -c -o $@ $<
	echo -n "$(CLEAR_SCREEN)"

libft:
	make -C $(LIBFT) --no-print-directory
#-------------------------------------CLEAN------------------------------------#

clean:
	$(RM) $(OBJS) $(DEPS) --no-print-directory
	make clean -C $(MLX) --no-print-directory
	make clean -C $(LIBFT) --no-print-directory
	rm -fr so_long.dSYM --no-print-directory

fclean: clean
	$(RM) $(NAME) --no-print-directory
	make fclean -C $(LIBFT) --no-print-directory
	make clean -C $(MLX) --no-print-directory

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT:
