/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:47:29 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 15:51:27 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "define_keys.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	double	cre;
	double	cim;
	double	newre;
	double	oldre;
	double	newim;
	double	oldim;
	double	movex;
	double	movey;
	double	zoom;
	char	color[4];
	int		k_color;
	double	palette;
	int		max_iter;
	int		iterations;
	int		lock;
	char	fract_set;
	int		bpp;
	int		size_line;
	int		endian;
	void	(*f)(struct s_env *e, int x, int y);
}				t_env;

void			read_input(int argc, char **argv);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_move(int x, int y, t_env *e);
void			m_zoom(t_env *e, int button, int x, int y);
void			key_move(t_env *e, int keycode);
int				expose_hook(t_env *e);
void			create_window(t_env *e);
int				key_hook(int keycode, t_env *e);
void			julia_set(t_env *e, int x, int y);
void			mandelbrot_set(t_env *e, int x, int y);
void			burning_ship(t_env *e, int x, int y);
void			get_color(t_env *e, void (*f)(t_env *e, int x, int y));
void			draw_image(t_env *e);
void			ini_enviroment(t_env *e);
void			print_menu_info(t_env *e);

#endif
