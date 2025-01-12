/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:31:05 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:31:07 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// [0...799] -> [-2..+2]
double	map(double value, t_map_range old_range, t_map_range new_range)
{
	return ((value - old_range.min) * (new_range.max - new_range.min)
		/ (old_range.max - old_range.min) + new_range.min);
}

// SUM complex
// fairly easy is vector addition
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

// SQUARE is trickier
// real = (x^2 - y^2)
// i = 2*x*y

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
