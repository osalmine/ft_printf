# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 12:39:52 by osalmine          #+#    #+#              #
#    Updated: 2020/01/02 15:37:29 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT =		libft.a
LIBFT_DIR =	libft/
FLAGS =		-Wall -Werror -Wextra
INCLUDE =	ft_printf.h
SOURCE =	ft_printf.c parse.c put_csp.c ft_len_put.c ft_itoa_base.c put_di.c \
			put_prosent.c put_o.c put_u.c put_x.c put_empty.c put_f.c
OBJ =		$(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@gcc $(FLAGS) -I$(INCLUDE) -c $(SOURCE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiled $(NAME)"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo Cleaned

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
