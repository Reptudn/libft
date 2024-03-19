# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2024/03/19 11:37:39 by jkauker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS 	= -Wall -Werror -Wextra -I ./
CFILES 	= src/ft_bzero.c src/ft_itoa.c src/ft_strrchr.c src/ft_atoi.c src/ft_calloc.c src/ft_isascii.c src/ft_isalnum.c src/ft_isalpha.c \
			ft_isdigit.c ft_isprint.c ft_memset.c ft_memchr.c ft_putstr_fd.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strncmp.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strtrim.c\
			ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c \
			get_next_line.c get_next_line_utils.c \
			ft_printf.c ./utils/conversion.c ./utils/base_system_conversion.c ./utils/helper.c ./utils/itoa.c ./utils/ltoa.c ./utils/put_hex.c
OBJ 	= $(CFILES:.c=.o)
CC		= cc

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all