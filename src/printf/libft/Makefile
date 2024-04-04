# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/03/10 16:09:18 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------VARIABLES----------------------------------#

NAME = libft.a

RM = rm -fr

INCL = libft.h
SRCS = ft_atoi.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c\
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c\
	   ft_bzero.c ft_memcmp.c ft_memmove.c ft_memchr.c ft_memcpy.c ft_calloc2.c\
	   ft_strlen2.c ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	   ft_strnstr.c ft_strncmp.c ft_substr.c ft_strjoin2.c ft_strtrim.c ft_split.c\
	   ft_strmapi.c ft_striteri.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
DEPS_BONUS = $(SRCS_BONUS:%.c=%.d)

CFLAGS = -Wall -Wextra -Werror -MMD -g

#------------------------------------EXECUTE-----------------------------------#

.SILENT:

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS) 
	ar rcs $(NAME) $(OBJS_BONUS) $(OBJS)

#-------------------------------------CLEAN------------------------------------#

clean:
	$(RM) $(NAME) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY: all clean fclean re bonus
.SILENT:
