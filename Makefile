# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 21:00:35 by ana-cast          #+#    #+#              #
#    Updated: 2024/09/06 12:18:32 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -f

INCLUDE = -I includes

SRCS = conversions.c \
	ft_printf.c

OBJECTS = $(SRCS:.c=.o)

BONUS_SR =	bonus/char_flags_bonus.c \
			bonus/conversions_bonus.c \
			bonus/ft_printf_bonus.c \
			bonus/flags_bonus.c \
			bonus/numeric_flags_bonus.c \
			bonus/utils_bonus.c

BONUS_OB = $(BONUS_SR:.c=.o)

all :$(NAME)

$(NAME) : $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus : $(BONUS_OB)
	@ar rc $(NAME) $(BONUS_OB)
	@ranlib $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) $(OBJECTS) $(BONUS_OB)

fclean: clean
	@$(RM) $(NAME)

re :
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re bonus