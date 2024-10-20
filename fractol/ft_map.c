/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:24:56 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/20 18:24:57 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	map_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_map_range	old_x;
	t_map_range	old_y;
	t_map_range	new_x;
	t_map_range	new_y;

	old_x.min = 0;
	old_x.max = WIDTH;
	old_y.min = 0;
	old_y.max = HEIGHT;
	new_x.min = -2;
	new_x.max = 2;
	new_y.min = -2;
	new_y.max = 2;
	z.real = map(x, old_x, new_x) * fractal->zoom + fractal->shift_x_value;
	z.imaginary = map(y, old_y, new_y) * fractal->zoom + fractal->shift_y_value;
	return (z);
}

// printf("Mapped Pixel (%d, %d) to complex z.real = %f, z.imaginary = %f\n", x,
//	y, z.real, z.imaginary);

int	compute_iterations(t_complex z, t_complex c, t_fractol *fractal)
{
	double	z_real2;
	double	z_imagninary2;
	double	tmp;
	int		i;

	z_real2 = z.real * z.real;
	z_imagninary2 = z.imaginary * z.imaginary;
	i = 0;
	while (i < fractal->iterations_definitions)
	{
		if ((z_real2 + z_imagninary2) > fractal->escp_value)
			return (i);
		tmp = z_real2 - z_imagninary2 + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = tmp;
		z_real2 = z.real * z.real;
		z_imagninary2 = z.imaginary * z.imaginary;
		i++;
	}
	return (-1);
}

static void	my_pixel_put(int x, int y, t_img *image, int colors)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = image->pixel_ptr + (y * image->line_len + x * (image->bpp) / 8);
		*(unsigned int *)dst = colors;
	}
}

static void	apply_colors(int x, int y, int iteration, t_fractol *fractal)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	if (iteration == -1)
		my_pixel_put(x, y, &fractal->image, 0x000000);
	else
	{
		red = (iteration * 5) % 256;
		green = (iteration * 7) % 256;
		blue = (iteration * 11) % 256;
		color = (red << 16) | (green << 8) | blue;
		my_pixel_put(x, y, &fractal->image, color);
	}
}

void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z = map_pixel(x, y, fractal);
	set_complex_const(&z, &c, fractal);
	i = compute_iterations(z, c, fractal);
	apply_colors(x, y, i, fractal);
}
