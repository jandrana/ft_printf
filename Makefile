# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 21:00:35 by ana-cast          #+#    #+#              #
#    Updated: 2024/05/27 19:52:59 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libftprintf.a

# Check if gcc is installed
HAS_GCC := $(shell command -v gcc 2> /dev/null)

# Check if clang is installed
HAS_CLANG := $(shell command -v clang 2> /dev/null)

ifdef HAS_GCC
  CC = gcc
else ifdef HAS_CLANG
  CC = clang
else
  $(error No compiler found)
endif

FLAGS = -Wall -Wextra -Werror
RM = rm -f
ECHO = echo n

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS = ft_printf_utils.c ft_printf.c

OBJECTS = $(SRCS:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head :
	@echo "$(COLOUR_MAGENTA)"
	@echo "   __ _                  _       _    __ "
	@echo "  / _| |                (_)     | |  / _|"
	@echo " | |_| |_     _ __  _ __ _ _ __ | |_| |_ "
	@echo " |  _| __|   | '_ \| '__| | '_ \| __|  _|"
	@echo " | | | |_    | |_) | |  | | | | | |_| |  "
	@echo " |_|  \__|   | .__/|_|  |_|_| |_|\__|_|  "
	@echo "       ______| |                         "
	@echo "      |______|_|      42MLG: by ana-cast \n"
	@echo "Proyect: \033[36m ft_printf $(COLOUR_MAGENTA)"
	@echo "Commands:\033[36m all clean fclean re $(COLOUR_END)\n"
	@printf "$(COLOUR_BLUE) 🛠   Compiler: $(CC) $(COLOUR_END)\n\n"

$(NAME) : $(OBJECTS)
	@printf "\n ⏱  Creating $(NAME)"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"

%.o : %.c
	@printf " ⏱  Compiling $@"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)\r  ✓   Compiled  $@ $(COLOUR_END)"

clean :
	@printf "\n$(COLOUR_YELLOW) 🗑   Removing objects$(COLOUR_END)"
	@$(RM) $(OBJECTS)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  objects $(COLOUR_END)"

fclean: clean
	@printf "$(COLOUR_YELLOW) 🗑   Removing $(NAME)$(COLOUR_END)"
	@$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  $(NAME) $(COLOUR_END)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all clean fclean re