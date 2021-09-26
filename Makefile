# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 18:55:56 by humanfou          #+#    #+#              #
#    Updated: 2021/09/25 23:30:31 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANITIZE = -fsanitize=address -fno-omit-frame-pointer

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBS_DIR = -Lmlx -Llibft

LIBS = -lmlx -lXext -lX11 -lm -lbsd -lft

INC = -Iincludes \
	-Ilibft \
	-Imlx \
	-Isrcs/drivers \
	-Isrcs/engine \
	-Isrcs/event \
	-Isrcs/init \
	-Isrcs/render \
	-Isrcs/set \
	-Isrcs/utils \
	-Isrcs/validate \

SRCS = srcs/main.c \
	$(wildcard srcs/drivers/*.c) \
	$(wildcard srcs/engine/*.c) \
	$(wildcard srcs/event/*.c) \
	$(wildcard srcs/init/*.c) \
	$(wildcard srcs/render/*.c) \
	$(wildcard srcs/set/*.c) \
	$(wildcard srcs/utils/*.c) \
	$(wildcard srcs/validate/*.c) \

OBJS = $(SRCS: %.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) -g3 $(SANITIZE) -o $(NAME) $(OBJS) $(INC) $(LIBS_DIR) $(LIBS)

clean:
	@cd mlx && $(MAKE) clean
	@cd libft && $(MAKE) clean
	/bin/rm -f *.o

fclean: clean
	@cd mlx && $(MAKE) fclean
	@cd libft && $(MAKE) fclean
	/bin/rm -fr $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
