/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:05:09 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 16:55:54 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 600

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		endian;
	int		sl;
	int		bpp;
	int		fract;
	int		color;
	int		julia_mouse;
	int		x;
	int		y;
	int		y_max;
	int		it;
	int		it_max;
	int		show_text;
	double	zoom;
	double	x1;
	double	y1;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
}			t_fractol;

int			key_hook(int keycode, t_fractol *data);
int			key_hook2(int keycode, t_fractol *data);
void		ft_zoom(int x, int y, t_fractol *data);
void		ft_dezoom(int x, int y, t_fractol *data);
int			mouse_hook(int mousecode, int x, int y, t_fractol *data);

void		mandelbrot_init(t_fractol *data);
void		mandelbrot_calc(t_fractol *data);
void		mandelbrot(t_fractol *data);

int			mouse_julia(int x, int y, t_fractol *data);
void		julia_init(t_fractol *data);
void		julia_calc(t_fractol *data);
void		julia(t_fractol *data);

void		burningship_init(t_fractol *data);
void		burningship_calc(t_fractol *data);
void		burningship(t_fractol *data);

int			ft_close(void);
void		put_pxl_to_img(t_fractol *data, int x, int y, int color);
void		put_text(t_fractol *data);

void		fract_calc(t_fractol *data);
void		fract_init(t_fractol *data);
void		mlx_win_init(t_fractol *data);
int			fract_comp(char **av, t_fractol *data);

#endif
