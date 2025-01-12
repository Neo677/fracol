# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thobenel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:31:18 by thobenel          #+#    #+#              #
#    Updated: 2024/10/14 13:31:19 by thobenel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = fractol

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION -arch arm64

# Détection de la plateforme (macOS ou Linux)
UNAME_S := $(shell uname -s)

# Options pour macOS
ifeq ($(UNAME_S), Darwin)
	INCLUDES = -I includes -I minilibx_opengl -I libft_2.0
	MLX = -Lminilibx_opengl -lmlx -framework OpenGL -framework AppKit
	LIBFT = -Llibft_2.0 -lft
	PLATFORM = macOS
# Options pour Linux
else
	INCLUDES = -I includes -I minilibx-linux -I libft_2.0
	MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
	LIBFT = -Llibft_2.0 -lft
	PLATFORM = Linux
endif

# Fichiers sources
SRCS = ft_init.c \
       ft_render.c \
       ft_events.c \
       ft_math_utils.c \
       ft_str_utils.c \
       ft_main.c \
       ft_touch_repeat.c \
       ft_map.c

# Objets
OBJS = $(SRCS:.c=.o)

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n\033[1;33m[INFO] Compilation en cours pour $(PLATFORM)...\033[0m"
	$(MAKE) -C libft_2.0
ifeq ($(PLATFORM), macOS)
	$(MAKE) -C minilibx_opengl
else
	$(MAKE) -C minilibx-linux
endif
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX) $(LIBFT) -o $(NAME)
	@echo "\n\033[1;32m[SUCCÈS] Compilation terminée pour $(PLATFORM) !\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft_2.0 clean
ifeq ($(PLATFORM), macOS)
	$(MAKE) -C minilibx_opengl clean
else
	$(MAKE) -C minilibx-linux clean
endif

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft_2.0 fclean
ifeq ($(PLATFORM), macOS)
	$(MAKE) -C minilibx_opengl clean
else
	$(MAKE) -C minilibx-linux clean
endif

re: fclean all