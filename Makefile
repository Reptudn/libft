NAME	:= libft.a

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -I ./include

SRCDIR := ./src/

SRCS	:= $(shell find **/*.c)
SRCS	:= $(addprefix $(SRCDIR),$(SRCS))

OBJDIR := ./obj/
OBJS	:= $(SRCS:.c=.o)
OBJS	:= $(addprefix $(OBJDIR),$(OBJS))

CC		:= cc

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[0;32mCompiling awesome libft...\033[0m\n"
	@ar -rcs $(NAME) $(FLAGS) $(OBJ)
	@printf "\033[0;32mLibft has compiled.\033[0m\n"

clean:
	@printf "\033[0;33mCleaning object files...\033[0m\n"
	@rm -rf $(OBJDIR)W
	@printf "\033[0;33mCleaned object files.\033[0m\n"

fclean: clean
	@printf "\033[0;31mCleaning everything...\033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[0;31mEverything cleaned.\033[0m\n"

debug: CFLAGS += -g -O0
debug: fclean $(NAME)
