# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:46:24 by akokoshk          #+#    #+#              #
#    Updated: 2018/02/01 22:28:57 by akokoshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRINTF MAKE

CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c pf_idu.c pf_parse_flags_b.c pf_uni.c \
	ft_init_pf_flist.c ft_strjoinandfree.c pf_o.c \
	pf_parse_flags_c.c pf_xp.c ft_itoabase.c pf_cs.c \
	pf_parse_flags_a.c pf_process_func.c
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)
	@echo "ft_printf objects compiled"

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFOLDER)
	@echo "ft_printf objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFOLDER)
	@echo "ft_printf objects fcleaned"

re:	fclean all
