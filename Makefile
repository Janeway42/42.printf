# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/20 12:22:54 by janeway       #+#    #+#                  #
#    Updated: 2021/05/13 14:53:55 by janeway       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ_FILES = ft_printf.o\
			get_data_1.o\
			get_data_2.o\
			convert_c.o\
			convert_s.o\
			convert_d.o\
			convert_d_utils.o\
			convert_u.o\
			convert_x.o\
			convert_p.o\
			convert_p_utils.o\
			utils_string.o\
			utils_print.o\

LIBFT = libft/libft.a
HEADER_FILES = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	cp $< $@
	ar -rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@ -g

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
