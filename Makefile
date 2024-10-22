# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 02:26:37 by theog             #+#    #+#              #
#    Updated: 2024/10/22 22:34:29 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC -g3

# Chemin de la bibliothèque readline
READLINE_DIR = /usr/local/opt/readline
INCLUDES = -I./ -I$(SRC_EXEC_DIR) -I$(SRC_PARSING_DIR) -I$(SRC_BUILTINS_DIR) \
           -I$(SRC_SIGNAL_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)/include
LDFLAGS = -L$(READLINE_DIR)/lib -lreadline -fPIE

# Dossiers
SRC_EXEC_DIR = ./exec
SRC_PARSING_DIR = ./parsing
SRC_BUILTINS_DIR = ./builtins
SRC_SIGNAL_DIR = ./signal
LIBFT_DIR = ./libft
OBJ_EXEC_DIR = ./exec_obj
OBJ_PARSING_DIR = ./parsing_obj
OBJ_BUILTINS_DIR = ./builtins_obj
OBJ_SIGNAL_DIR = ./signal_obj

# Fichiers sources pour exec, parsing et builtins
EXEC_FILES = ft_all.c ft_check.c ft_child.c ft_exec_one.c ft_heredoc.c \
             ft_make_exec.c ft_path.c ft_pipe_lst.c ft_secure.c \
             ft_set.c ft_while_cmd.c ft_token_to_exec.c ft_redir.c lst_file.c \
			 ft_sig.c exit_code.c

PARSING_FILES = TO_BIN_main_test.c TO_BIN_print_functions.c pft_join_all.c \
                garbage_collector.c helpers.c make_token_and_append.c \
                make_token_and_append_helpers.c parsing_main.c parsing_main_helpers.c \
                replace_vars.c pft_itoa.c pft_strdup.c pft_strjoin.c pft_substr.c \
                split_array_tokens.c replace_vars_helpers.c parsing_main2.c \
                parsing_main3.c

BUILTINS_FILES = detect_and_launch.c ft_cd.c ft_echo.c ft_env.c ft_exit.c \
                 ft_export.c ft_export_helpers.c ft_pwd.c ft_unset.c

SIGNAL_FILES = signal.c

# Fichiers objets (dans les dossiers correspondants)
OBJ_EXEC = $(addprefix $(OBJ_EXEC_DIR)/, $(EXEC_FILES:.c=.o))
OBJ_PARSING = $(addprefix $(OBJ_PARSING_DIR)/, $(PARSING_FILES:.c=.o))
OBJ_BUILTINS = $(addprefix $(OBJ_BUILTINS_DIR)/, $(BUILTINS_FILES:.c=.o))
OBJ_SIGNAL = $(addprefix $(OBJ_SIGNAL_DIR)/, $(SIGNAL_FILES:.c=.o))

# Bibliothèque libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règles
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ_EXEC) $(OBJ_PARSING) $(OBJ_BUILTINS) $(OBJ_SIGNAL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_EXEC) $(OBJ_PARSING) $(OBJ_BUILTINS) $(OBJ_SIGNAL) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compilation des fichiers objets dans exec
$(OBJ_EXEC_DIR)/%.o: $(SRC_EXEC_DIR)/%.c
	@mkdir -p $(OBJ_EXEC_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers objets dans parsing
$(OBJ_PARSING_DIR)/%.o: $(SRC_PARSING_DIR)/%.c
	@mkdir -p $(OBJ_PARSING_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers objets dans signal
$(OBJ_SIGNAL_DIR)/%.o: $(SRC_SIGNAL_DIR)/%.c
	@mkdir -p $(OBJ_SIGNAL_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers objets dans builtins
$(OBJ_BUILTINS_DIR)/%.o: $(SRC_BUILTINS_DIR)/%.c
	@mkdir -p $(OBJ_BUILTINS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des objets et de l'exécutable
clean:
	rm -rf $(OBJ_EXEC_DIR) $(OBJ_PARSING_DIR) $(OBJ_BUILTINS_DIR) $(OBJ_SIGNAL_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild complet
re: fclean all

run:
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re
