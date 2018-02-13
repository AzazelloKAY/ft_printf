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
SOURCES = ft_itoabase.c ft_strjoinandfree.c pf_f.c pf_n_color_quote.c \
	pf_parse_flags_a.c pf_parse_flags_c.c pf_process_func.c pf_xp.c \
	ft_init_pf_flist.c ft_printf.c pf_cs.c pf_idu.c pf_ob.c pf_parse_flags_b.c \
	pf_parse_flags_d.c pf_uni.c
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)
	@echo "ft_printf objects compiled"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJECTS)
	@echo "ft_printf objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf objects fcleaned"

re:	fclean all
