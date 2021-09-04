# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 18:55:56 by humanfou          #+#    #+#              #
#    Updated: 2021/09/03 18:55:57 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANITIZE = -O1 -g -fsanitize=address -fno-omit-frame-pointer

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBS_DIR = -Lmlx -Llibft

LIBS = -lmlx -lXext -lX11 -lm -lbsd -lft

INC = -Iincludes \
	-Ilibft \
	-Imlx \
	-Isrcs/utils \
	-Isrcs/validate \

SRCS = srcs/main.c \
	$(wildcard srcs/utils/*.c) \
	$(wildcard srcs/validate/*.c) \

OBJS = $(SRCS: %.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(CC) $(SANITIZE) -o $(NAME) $(OBJS) $(INC) $(LIBS_DIR) $(LIBS)

clean:
	@cd libft && $(MAKE) clean
	@rm -fr *.o

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -fr $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
