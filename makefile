# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:43:23 by root              #+#    #+#              #
#    Updated: 2024/10/12 11:15:59 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS_SERVEUR = serveur.c
SRCS_CLIENT = client.c

# Fichiers objets
OBJS_SERVEUR = $(SRCS_SERVEUR:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Règle par défaut
all: serveur client

# Règle pour compiler la bibliothèque libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Règle pour compiler le serveur
serveur: $(OBJS_SERVEUR) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVEUR) $(LIBFT)

# Règle pour compiler le client
client: $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) $(LIBFT)

# Règle générique pour compiler les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tout nettoyer
clean:
	rm -f $(OBJS_SERVEUR) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean

# Règle pour tout nettoyer y compris les exécutables
fclean: clean
	rm -f serveur client
	$(MAKE) -C $(LIBFT_DIR) fclean

# Règle pour tout recompiler
re: fclean all

.PHONY: all clean fclean re
