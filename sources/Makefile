# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:46:24 by akokoshk          #+#    #+#              #
#    Updated: 2018/02/01 21:33:09 by akokoshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRINTF MAKE

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf
SOURCES = fdffunctions.c fdfmain.c fdfmakeres.c fdfperspective.c ft_brez.c \
fdfkeyhooks.c fdfmakeimg.c fdfparser.c fdfrotation.c
OBJFOLDER = sources
OBJECTS = $(SOURCES:.c=.o)
LIBFOLDER = libft

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	@make -C $(LIBFOLDER)
	@$(CC) $(FLAGS) $(OBJECTS) -L $(LIBFOLDER) -lft -o $(NAME)
	@echo "ft_printf compiled"

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFOLDER)
	@echo "ft_printf cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFOLDER)
	@echo "ft_printf fcleaned"

re:	fclean all
