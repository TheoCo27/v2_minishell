# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 12:10:54 by tcohen            #+#    #+#              #
#    Updated: 2024/10/13 19:56:21 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIC

INCLUDES = -I .

OBJDIR = obj

FUNC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_wdcount.c ft_free_all.c

FUNCADDITIONAL =	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c ft_str_free_join.c ft_charcmp.c \
			ft_str_setonly.c ft_tabstr.c ft_atleast_set.c ft_count_char.c \
			ft_get_index.c garbage.c ft_malloc.c ft_free.c

BONUS =	$(addprefix ft_, $(addsuffix _bonus.c, lstadd_back \
		lstadd_front \
		lstclear \
		lstdelone \
		lstiter \
		lstlast \
		lstmap \
		lstnew \
		lstsize))

SRCS = $(FUNC) $(FUNCADDITIONAL)

SRCSALL = $(SRCS) $(BONUS)

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJSALL = $(addprefix $(OBJDIR)/, $(SRCSALL:.c=.o))

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rsc $(NAME) $(OBJS)

all : $(NAME)

bonus : $(OBJSALL)
	ar -rsc $(NAME) $(OBJSALL)

clean : 
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

