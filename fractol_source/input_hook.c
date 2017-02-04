/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:06:44 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 16:18:37 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	m_zoom(t_env *e, int button, int x, int y)
{
	if (button == M_ZOOM_IN && e->zoom < 8 * pow(10, 13))
	{
		e->zoom *= 1.2;
		e->movex += (x - WIN_W / 2) / e->zoom / 1.3;
		e->movey += (y - WIN_H / 2) / e->zoom / 1.3;
	}
	else if (button == M_ZOOM_OUT && e->zoom > 0.3)
		e->zoom /= 1.2;
	draw_image(e);
}

void	key_move_col(t_env *e, int keycode)
{
	if (keycode == RED)
		e->k_color = RED;
	else if (keycode == GREEN)
		e->k_color = GREEN;
	else if (keycode == BLUE)
		e->k_color = BLUE;
	else if (keycode == F2_JULIA)
	{
		e->f = julia_set;
		e->fract_set = 'J';
		ini_enviroment(e);
	}
	else if (keycode == F3_MANDELBROT)
	{
		e->f = mandelbrot_set;
		e->fract_set = 'M';
		ini_enviroment(e);
	}
	else if (keycode == F4_SHIP)
	{
		e->f = burning_ship;
		e->fract_set = 'B';
		ini_enviroment(e);
	}
}

void	key_move(t_env *e, int keycode)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == MOVE_UP)
		e->movey -= 30.2 / e->zoom;
	else if (keycode == MOVE_DOWN)
		e->movey += 30.2 / e->zoom;
	else if (keycode == MOVE_LEFT)
		e->movex -= 30.2 / e->zoom;
	else if (keycode == MOVE_RIGHT)
		e->movex += 30.2 / e->zoom;
	else if (keycode == LOCK_C)
		e->lock = (e->lock) ? 0 : 1;
	else if (keycode == PLUS_ITER && e->max_iter < MAX_ITER)
		e->max_iter *= 1.2;
	else if (keycode == MINUS_ITER && e->max_iter > MIN_ITER)
		e->max_iter /= 1.2;
	else if (keycode == 91)
		e->palette += 1;
	else if (keycode == 84)
		e->palette -= 1;
	else if (keycode == RESET_IMG)
		ini_enviroment(e);
	else
		key_move_col(e, keycode);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (!e->lock)
	{
		if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
		{
			e->cre = ((4.f * (double)x / (double)WIN_W * e->zoom - 2.f));
			e->cim = ((4.f * (double)y / (double)WIN_H * e->zoom - 2.f));
			draw_image(e);
		}
	}
	return (0);
}
