# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torsini <torsini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:43:23 by root              #+#    #+#              #
#    Updated: 2024/10/16 15:12:36 by torsini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Fichiers objets
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Règle par défaut
all: server client

# Règle pour compiler la bibliothèque libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Règle pour compiler le serveur
server: $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(LIBFT)

# Règle pour compiler le client
client: $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) $(LIBFT)

# Règle générique pour compiler les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tout nettoyer
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean

# Règle pour tout nettoyer y compris les exécutables
fclean: clean
	rm -f server client
	$(MAKE) -C $(LIBFT_DIR) fclean

# Règle pour tout recompiler
re: fclean all

.PHONY: all clean fclean re
