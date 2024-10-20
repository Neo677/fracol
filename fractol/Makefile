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
CFLAGS = -Wall -Wextra -Werror

# MAC OS
# INCLUDES = -I includes -I minilibx_opengl_20191021 -I ../libft

# Linux
INCLUDES = -I includes -I minilibx-linux -I ../libft 

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

# MAC OS
MLX_MAC = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
LIBFT = -L../libft -lft

# Linux
MLX_LINUX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
LIBFT = -L../libft -lft

# Plateforme (change entre Mac OS et Linux selon la situation)
PLATFORM = $(MLX_LINUX) # Change pour $(MLX_MAC) si tu utilises Mac

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(PLATFORM) $(LIBFT) -o $(NAME)
	@echo "\n\033[1;32mCompilation terminée avec succès !\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all
