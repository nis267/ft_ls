# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dewalter <dewalter@student.le-101.>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:31:56 by dewalter     #+#   ##    ##    #+#        #
#    Updated: 2018/02/19 09:17:32 by dewalter    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = libft.a

CC = gcc

COLOR = echo

CC_FLAGS = -c -Wall -Werror -Wextra

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memccpy.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memmove.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_memalloc.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memdel.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strncat.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strchr.c \
	  ft_strstr.c \
	  ft_strrchr.c \
	  ft_putnbr_fd.c \
	  ft_putendl_fd.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strlcat.c \
	  ft_lstnew.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_itoa_base.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_sort_integer_table.c \
	  ft_range.c \
	  ft_ltoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

./%.o: ./%.c
	@ echo "\033[1mCompilation de \033[33m$<\033[37m en \033[32m$@\033[0m ✅ "
	@$(CC) $(CC_FLAGS) -I includes/ -o $@ -c $<

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
