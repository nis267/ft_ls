# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:16:56 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/02/21 18:06:04 by dewalter    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = ft_ls

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = -L $(LIBFT_PATH) -lft

CC = gcc

COLOR = echo

CC_FLAGS = -Wall -Werror -Wextra

SRC =		ft_ls.c \
			ft_ls_recup_data.c \
			ft_ls_recup_space.c \
			ft_ls_recup_perm.c \
			ft_ls_if_file.c \
			ft_init_struct.c \
			ft_sort.c \
			ft_display_part_1.c \
			ft_display_part_2.c \
			ft_display_part_3.c \
			ft_display_error.c

INCLUDES_PATH = includes

INCLUDES = -I $(LIBFT_PATH) -I $(INCLUDES_PATH)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ echo "\033[1mCompilation de ls \033[34m$<\033[37m en \033[31m$@\033[0m ✅ "
	@$(CC) $(CC_FLAGS) -o $@ $^ $(LIBFT_INC)

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o: %.c ./$(NAME).h
	@ echo "\033[1mCompilation de \033[33m$<\033[37m en \033[32m$@\033[0m ✅ "
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all
