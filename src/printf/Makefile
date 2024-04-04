# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:20:32 by erigonza          #+#    #+#              #
#    Updated: 2024/03/02 14:13:10 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------VARIABLES----------------------------------#

NAME		= libftprintf.a

LIBFT		= libft/libft.a

CC			= gcc
CFLAGS		= -g -MMD -Wall -Wextra -Werror
INCS		= -I $(dir $(LIBFT))
AR			= ar -rcs
RM			= rm -rf
INC			=  ft_printf.h\
			   libft/libft.h

SRCS		= ft_printf.c ft_putchar_error.c 
OBJS		= $(SRCS:.c=.o)
DEPS		= $(SRCS:.c=.d)

#------------------------------------EXECUTE-----------------------------------#

all:		
			make -C $(dir $(LIBFT)) --no-print-directory
			make $(NAME) --no-print-directory
			echo "LIBFT Compiled!"

%.o: %.c Makefile
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@  -I libft/libft.a

$(NAME):	$(OBJS) $(LIBFT)
			$(AR) $(NAME) $(OBJS) 
			echo "$(NAME) Compiled!"

$(LIBFT):
			make -C $(dir $(LIBFT)) --no-print-directory

#-------------------------------------CLEAN------------------------------------#

clean:
			make clean -C $(dir $(LIBFT)) --no-print-directory
			$(RM) $(OBJS) $(DEPS)

fclean:		clean
			make fclean -C $(dir $(LIBFT)) --no-print-directory
			$(RM) $(NAME)

re:			fclean all

#--------------------------------------...-------------------------------------#

-include $(DEPS)

.PHONY:		all clean fclean re
.SILENT:
