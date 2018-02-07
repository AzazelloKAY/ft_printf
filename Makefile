# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:46:24 by akokoshk          #+#    #+#              #
#    Updated: 2018/02/01 22:21:01 by akokoshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAIN MAKE

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = sources
LIBFOLDER = libft
OBJECTS_PF = $(SOURCES)/*.o
OBJECTS_LIB = $(LIBFOLDER)/*.o

all: $(NAME)

$(NAME):
	@make -C $(LIBFOLDER)
	@make -C $(SOURCES)
	@ar rc $(NAME) $(OBJECTS_PF) $(OBJECTS_LIB)
	@echo "libftprintf.a compiled"

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFOLDER)
	@make clean -C $(SOURCES)
	@echo "all cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFOLDER)
	@make fclean -C $(SOURCES)
	@echo "all fcleaned"

re:	fclean all
