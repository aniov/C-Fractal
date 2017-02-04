/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:13:30 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 16:16:57 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ini_enviroment(t_env *e)
{
	if (e->fract_set == 'J')
	{
		e->cre = -0.02;
		e->cim = 0.7;
	}
	e->zoom = 1;
	e->movex = 0;
	e->movey = 0;
	e->color[3] = '\0';
	e->max_iter = 50;
	e->lock = 0;
	e->k_color = RED;
	e->palette = 1;
}

void	get_input_color(t_env *e)
{
	if (e->k_color == RED)
	{
		e->color[2] = 255;
		e->color[1] = 255 - e->iterations * 1.5 * e->palette;
		e->color[0] = 255 - e->iterations * 2.4 * e->palette;
	}
	else if (e->k_color == GREEN)
	{
		e->color[2] = 50 + e->iterations * 9.5 * e->palette;
		e->color[1] = 25 + e->iterations * 1.5 * e->palette;
		e->color[0] = 0 - e->iterations * 2.4 * e->palette;
	}
	else if (e->k_color == BLUE)
	{
		e->color[2] = 255 - e->iterations * 1.5 * e->palette;
		e->color[1] = 255 - e->iterations * 2.4 * e->palette;
		e->color[0] = 255;
	}
}

void	get_color(t_env *e, void (*f)(t_env *e, int x, int y))
{
	int x;
	int y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			f(e, x, y);
			get_input_color(e);
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 2] = e->color[2];
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 1] = e->color[1];
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 0] = e->color[0];
			y++;
		}
		x++;
	}
}

void	create_window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W + WIN_MENU, WIN_H, "Fractal sets");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_move, e);
	mlx_hook(e->win, 4, (1L << 2), mouse_hook, e);
	mlx_loop(e->mlx);
}
