# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:47:22 by abouvero          #+#    #+#              #
#    Updated: 2018/01/16 17:21:11 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_strtoupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_list_size.c \
	   ft_list_at.c \
	   ft_list_last.c \
	   ft_list_pop_front.c \
	   ft_list_pop_back.c \
	   ft_list_push_front.c \
	   ft_list_push_back.c \
	   ft_print_list.c \
	   get_next_line.c \
	   ft_max_itoa_base.c \
	   ft_umax_itoa_base.c \
	   ft_putwchar.c \
	   ft_printf/c_conv.c \
	   ft_printf/colorise.c \
	   ft_printf/flags.c \
	   ft_printf/format_validation.c \
	   ft_printf/ft_printf.c \
	   ft_printf/get_struct.c \
	   ft_printf/precision.c \
	   ft_printf/redirect_comp.c \
	   ft_printf/redirect.c \
	   ft_printf/str_converter.c \
	   ft_printf/width.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libft.h \
		   get_next_line.h \
		   ft_printf.h

OBJDIR =./obj/
INCDIR =./includes/
SRCDIR =./src/

NAME =libft.a
FLAGS =-Wall -Werror -Wextra

SRC = $(addprefix $(SRCDIR), $(SRC_NAME))
INC = $(addprefix $(INCDIR), $(INC_NAME))
OBJ = $(addprefix $(OBJDIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR) && mkdir -p $(OBJDIR)/ft_printf/
	gcc -o $@ -c $< $(FLAGS) -I $(INCDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
