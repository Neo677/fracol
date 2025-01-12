/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:30:53 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:30:55 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//				Linux
static void	malloc_error(t_fractol *fractal)
{
	if (fractal->mlx_window != NULL)
		mlx_destroy_image(fractal->mlx_connect, fractal->mlx_window);
	if (fractal->image.image_ptr != NULL)
		mlx_destroy_window(fractal->mlx_connect, fractal->image.image_ptr);
	if (fractal->mlx_connect != NULL)
		free(fractal->mlx_connect);
	perror("probleme avec malloc");
	exit(EXIT_FAILURE);
}

//				MAC OS
// static void	malloc_error(t_fractol *fractal)
// {
// 	if (fractal->mlx_window)
// 		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
// 	if (fractal->mlx_connect)
// 	{
// 		//mlx_destroy_display(fractal->mlx_connect);
// 		free(fractal->mlx_connect);
// 	}
// 	perror("probleme avec malloc");
// 	exit(EXIT_FAILURE);
// }

void	data_init(t_fractol *fractal, double julia_x, double julia_y, int ac)
{
	fractal->escp_value = 5;
	fractal->iterations_definitions = 20;
	fractal->shift_x_value = 0.0;
	fractal->shift_y_value = 0.0;
	fractal->zoom = 1.0;
	if (ac == 4)
	{
		fractal->julia_x = julia_x;
		fractal->julia_y = julia_y;
	}
	else
	{
		fractal->julia_x = -0.07;
		fractal->julia_y = 0.27015;
	}
}

// fractal->escp_value = 4;               // Valeur d'échappement (2^2)
// fractal->iterations_definitions = 150; // Nombre d'itérations
// fractal->shift_x_value = 0.0;          // Décalage en X
// fractal->shift_y_value = 0.0;          // Décalage en Y
// fractal->zoom = 1.0;                   // Zoom par défaut
// // Valeurs par défaut pour Julia
// fractal->julia_x = -0.7;
// fractal->julia_y = 0.27015;

static void	event_init(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractol *fractal, double julia_x, double julia_y,
		int argc)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		malloc_error(fractal);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
		malloc_error(fractal);
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connect, WIDTH,
			HEIGHT);
	if (fractal->image.image_ptr == NULL)
		malloc_error(fractal);
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp, &fractal->image.line_len,
			&fractal->image.endian);
	fractal->key_down = 0;
	fractal->key_left = 0;
	fractal->key_right = 0;
	fractal->key_up = 0;
	event_init(fractal);
	data_init(fractal, julia_x, julia_y, argc);
	fractal_render(fractal);
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
