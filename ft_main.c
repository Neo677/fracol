/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:30:57 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:31:03 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_up(t_fractol *fractal)
{
	if (fractal->mlx_connect && fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	if (fractal->image.image_ptr)
		mlx_destroy_image(fractal->mlx_connect, fractal->image.image_ptr);
	free(fractal);
}

static void	error_manage(void)
{
	putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;
	double		julia_x;
	double		julia_y;

	if (argc == 2 && !ft_strncompare(argv[1], "mandelbrot", 10))
	{
		fractal.name = argv[1];
		fractal_init(&fractal, 0, 0, argc);
	}
	else if (argc == 4 && !ft_strncompare(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		julia_x = ft_atodbl(argv[2]);
		julia_y = ft_atodbl(argv[3]);
		fractal_init(&fractal, julia_x, julia_y, argc);
	}
	else
		error_manage();
	mlx_loop(fractal.mlx_connect);
	clean_up(&fractal);
	return (0);
}
