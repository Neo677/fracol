/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:30:38 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:30:39 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "minilibx_opengl_20191021/mlx.h"

# include "libft_2.0/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx_opengl/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>  // debugging
# include <stdlib.h> // malloc
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define ERROR_MESSAGE \
	"Pls enter \n\t\"./fractol mandelbrot\" \
						OU \n\t\"./fractol julia <value real> \
						<value imaginary>\""

/*gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
make sure the minilibX is compiled!
of course git clone the MLX*/

//		colors
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

// 		psychedelic colors
# define MAGENTA_BURTS 0xFF00FF      // A vibrant magenta
# define LIME_SHOCKS 0xCCFF00        // A blinding lime
# define NEON_ORANGE 0xFF6600        // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC         // A bright turquoise
# define HOT_PINK 0xFF66B2           // As the name suggest !
# define ELECTRIC_BLUE 0x0066FF      // A radiant blue
# define LAVA_RED 0xFF3300           // A bright, molten red

// 	complex value
typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_image
{
	void	*image_ptr;
	// ptr to image struct
	char	*pixel_ptr;
	// ptr vers le pixel actuelle
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_map_range
{
	double	min;
	double	max;
}			t_map_range;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connect;
	// init de la mlx
	void	*mlx_window;
	// new window
	t_img	image;
	// image
	int		iterations_definitions;
	// == 255
	/* hooks member variable */
	double	escp_value;

	double	shift_x_value;
	double	shift_y_value;

	double	target_x_value;
	double	target_y_value;

	double	zoom;

	double	julia_x;
	double	julia_y;

	double	target_julia_x;
	double	target_julia_y;

	int		key_left;
	int		key_right;
	int		key_up;
	int		key_down;

}			t_fractol;

//			utils 			//
int			ft_strncompare(const char *s1, const char *s2, size_t n);
void		putstr_fd(char *s, int fd);
double		ft_atodbl(char *s);

void		handle_pixel(int x, int y, t_fractol *fractal);

// 			init 			//
void		fractal_init(t_fractol *fractal, double julia_x, double julia_y,
				int ac);
void		data_init(t_fractol *fractal, double julia_x, double julia_y,
				int ac);

//			render			//
void		fractal_render(t_fractol *fractal);

//			math utils		//
double		map(double value, t_map_range old_value, t_map_range new_value);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		set_complex_const(t_complex *z, t_complex *c, t_fractol *fractal);

// 			hook event		//
int			key_handler(int keysym, t_fractol *fractal);

//			cleaner			//
int			close_handler(t_fractol *fractal);
int			mouse_handler(int button, int x, int y, t_fractol *fractal);

//			loop for maintain key	//
int			loop_hook(t_fractol *fractal);
int			key_press(int key, t_fractol *fractal);
int			key_release(int key, t_fractol *fractal);

#endif
