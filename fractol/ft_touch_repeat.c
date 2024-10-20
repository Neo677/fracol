/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch_repeat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:47:45 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/20 16:47:47 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_fractol *fractal)
{
	if (fractal->key_down)
		fractal->shift_x_value -= 0.01 / fractal->zoom;
	else if (fractal->key_down)
		fractal->shift_x_value += 0.01 / fractal->zoom;
	else if (fractal->key_down)
		fractal->shift_y_value -= 0.01 / fractal->zoom;
	else if (fractal->key_down)
		fractal->shift_y_value += 0.01 / fractal->zoom;
	fractal_render(fractal);
	return (0);
}

int	key_press(int key, t_fractol *fractal)
{
	if (key == XK_Left)
		fractal->key_left = 1;
	else if (key == XK_Right)
		fractal->key_right = 1;
	else if (key == XK_Up)
		fractal->key_up = 1;
	else if (key == XK_Down)
		fractal->key_down = 1;
	return (0);
}

int	key_release(int key, t_fractol *fractal)
{
	if (key == XK_Left)
		fractal->key_left = 0;
	else if (key == XK_Right)
		fractal->key_right = 0;
	else if (key == XK_Up)
		fractal->key_up = 0;
	else if (key == XK_Down)
		fractal->key_down = 0;
	return (0);
}
