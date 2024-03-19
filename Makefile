# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2024/03/19 11:55:58 by jkauker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS 	= -Wall -Werror -Wextra -I ./
CFILES 	= src/ft_bzero.c src/ft_itoa.c src/ft_strrchr.c src/ft_atoi.c src/ft_calloc.c src/ft_isascii.c src/ft_isalnum.c src/ft_isalpha.c \
			src/ft_isdigit.c src/ft_isprint.c src/ft_memset.c src/ft_memchr.c src/ft_putstr_fd.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c \
			src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c \
			src/ft_strjoin.c src/ft_strlcat.c src/ft_strncmp.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strnstr.c src/ft_strtrim.c\
			src/ft_substr.c src/ft_tolower.c src/ft_toupper.c src/ft_isspace.c \
			src/get_next_line.c src/get_next_line_utils.c \
			src/ft_printf.c src/utils/conversion.c src/utils/base_system_conversion.c src/utils/helper.c src/utils/itoa.c src/utils/ltoa.c src/utils/put_hex.c
OBJS	:= $(SRCS:.c=.o)
CC		= cc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
		@printf "\033[0;32m[LIBFT] Compiling libft...\033[0m\n"
		ar -rcs $(NAME) $(OBJS)
		@printf "\033[0;32m[LIBFT] libft compiled successfully!\033[0m\n"

clean:
		@printf "\033[0;33m[LIBFT] Cleaning libft...\033[0m\n"
		@rm -rf $(OBJS)
		@printf "\033[0;33m[LIBFT] libft cleaned successfully!\033[0m\n"

fclean: clean
		@printf "\033[0;31m[LIBFT] Removing libft...\033[0m\n"
		@rm -f $(NAME)
		@printf "\033[0;31m[LIBFT] libft removed successfully!\033[0m\n"

re: fclean all