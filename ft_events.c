/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:30:41 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:30:50 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//		linux
// int	close_handler(t_fractol *fractal)
// {
// 	if (fractal->mlx_window != NULL)
// 	{
// 		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
// 		fractal->mlx_window = NULL;
// 	}
// 	if (fractal->image.image_ptr != NULL)
// 	{
// 		mlx_destroy_image(fractal->mlx_connect, fractal->image.image_ptr);
// 		fractal->image.image_ptr = NULL;
// 	}
// 	mlx_destroy_display(fractal->mlx_connect);
// 	free(fractal->mlx_connect);
// 	exit(0);
// 	return (0);
// }

		// mac OS
int	close_handler(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->image.image_ptr);
	// *mlx_ptr, 		// *img_ptr))
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	// *mlx_ptr, 			// *win_ptr))
	free(fractal->mlx_connect);                // ptr
	exit(EXIT_SUCCESS);                        // status
}

//			Linux
// static void	ft_julia_set(int keysym, t_fractol *fractal)
// {
// 	if (keysym == XK_a)
// 		fractal->julia_y += 0.1;
// 	else if (keysym == XK_d)
// 		fractal->julia_y -= 0.1;
// 	else if (keysym == XK_w)
// 		fractal->julia_x -= 0.1;
// 	else if (keysym == XK_s)
// 		fractal->julia_x += 0.1;
// 	else if (keysym == XK_0)
// 		fractal->iterations_definitions += 5;
// 	else if (keysym == XK_minus)
// 		fractal->iterations_definitions -= 5;
// }

				// for MAC OS
static void	ft_julia_set(int keysym, t_fractol *fractal)
{
	if (keysym == 2)
		fractal->julia_y += 0.1;
	else if (keysym == 0)
		fractal->julia_y -= 0.1;
	else if (keysym == 1)
		fractal->julia_x += 0.1;
	else if (keysym == 13)
		fractal->julia_x -= 0.1;
	else if (keysym == 48)
		fractal->iterations_definitions += 10;
	else if (keysym == 45)
		fractal->iterations_definitions -= 10;
	if (fractal->iterations_definitions <= 12)
		fractal->iterations_definitions += 252;
	if (fractal->iterations_definitions > 262)
		fractal->iterations_definitions -= 252;
}

//				For MAC OS
// the touch for driving in the fractal it different so :
// 	left = 124
// 	right = 123
// 	up = 125
// 	down = 126

// On mac os qwerty the colors changer set is 'tab' for less and 'n' for iterate

int	key_handler(int keysym, t_fractol *fractal)
{
	ft_printf("Key pressed: %d\n", keysym);
	if (keysym == 53)
		close_handler(fractal);
	if (keysym == 2)
		fractal->shift_x_value += (0.1 * fractal->zoom);
	else if (keysym == 0)
		fractal->shift_x_value -= (0.1 * fractal->zoom);
	else if (keysym == 1)
		fractal->shift_y_value -= (0.1 * fractal->zoom);
	else if (keysym == 13)
		fractal->shift_y_value += (0.1 * fractal->zoom);
	if (!ft_strncompare(fractal->name, "julia", 5))
		ft_julia_set(keysym, fractal);
	else if (keysym == 45)
		fractal->iterations_definitions += 1;
	else if (keysym == 48)
		fractal->iterations_definitions -= 1;
	if (fractal->iterations_definitions <= 12)
		fractal->iterations_definitions += 252;
	if (fractal->iterations_definitions > 262)
		fractal->iterations_definitions -= 252;
	ft_printf("colors = %d\n", fractal->iterations_definitions);
	fractal_render(fractal);
	return (0);
}
// 						Linux
// key press protocole
// int (*f)(int keycode, void *param)
// int	key_handler(int keysym, t_fractol *fractal)
// {
// 	ft_printf("ite: %d\n", fractal->iterations_definitions);
// 	if (!ft_strncompare(fractal->name, "julia", 5))
// 		ft_julia_set(keysym, fractal);
// 	if (keysym == XK_Escape)
// 		close_handler(fractal);
// 	if (keysym == XK_Right)
// 		fractal->shift_x_value += (0.1 * fractal->zoom);
// 	else if (keysym == XK_Left)
// 		fractal->shift_x_value -= (0.1 * fractal->zoom);
// 	else if (keysym == XK_Up)
// 		fractal->shift_y_value -= (0.1 * fractal->zoom);
// 	else if (keysym == XK_Down)
// 		fractal->shift_y_value += (0.1 * fractal->zoom);
// 	else if (keysym == XK_p)
// 		fractal->iterations_definitions += 10;
// 	else if (keysym == XK_l)
// 		fractal->iterations_definitions -= 10;
// 	fractal_render(fractal);
// 	return (0);
// }

int	mouse_handler(int button, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		fractal->zoom *= 0.91;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
