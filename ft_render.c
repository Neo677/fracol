/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:31:10 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:31:11 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_complex_const(t_complex *z, t_complex *c, t_fractol *fractal)
{
	if (!ft_strncompare(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imaginary = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

// actual
/*
		0-----------------800    (-2)------------(+2)
		|					|    |					|
		|					|		|					|
	800 |					|		|					|
		|					|		|					|
		|					|		|					|
		|					|		|					|
		---------------------		--------------------
	MANDELBROT :
	z = z^2 + c
	z initialise is (0, 0)
	c is the actuall point

	JULIA :
	./fractol julia <real> <i>
	z = pixel_point +constant
*/

void	fractal_render(t_fractol *fractal)
{
	int	x;
	int	y;

	if (fractal->image.image_ptr != NULL)
	{
		mlx_destroy_image(fractal->mlx_connect, fractal->image.image_ptr);
		fractal->image.image_ptr = NULL;
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connect, WIDTH,
			HEIGHT);
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp, &fractal->image.line_len,
			&fractal->image.endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
