/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:51:57 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 16:05:19 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_env *e, int x, int y)
{
	int i;

	i = 0;
	e->newre = (x - WIN_W / 2) / (0.3 * e->zoom * WIN_W) + e->movex / WIN_W;
	e->newim = (y - WIN_H / 2) / (0.3 * e->zoom * WIN_H) + e->movey / WIN_H;
	while (i < e->max_iter)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim + e->cre;
		e->newim = 2 * e->oldre * e->oldim + e->cim;
		if ((e->newre * e->newre + e->newim * e->newim) > 4)
			break ;
		i++;
	}
	e->iterations = i;
}

void	mandelbrot_set(t_env *e, int x, int y)
{
	int i;

	i = 0;
	e->cre = (x - WIN_W / 2) / (0.3 * e->zoom * WIN_W) + e->movex / WIN_W
			- 0.25;
	e->cim = (y - WIN_H / 2) / (0.3 * e->zoom * WIN_H) + e->movey / WIN_H;
	e->newre = 0;
	e->newim = 0;
	while (i < e->max_iter)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim + e->cre;
		e->newim = 2 * e->oldre * e->oldim + e->cim;
		if ((e->newre * e->newre + e->newim * e->newim) > 4)
			break ;
		i++;
	}
	e->iterations = i;
}

void	burning_ship(t_env *e, int x, int y)
{
	int i;

	i = 0;
	e->cre = (x - WIN_W / 2) / (0.3 * e->zoom * WIN_W) + e->movex / WIN_W - 0.3;
	e->cim = (y - WIN_H / 2) / (0.3 * e->zoom * WIN_H) + e->movey / WIN_H - 0.5;
	e->newre = 0;
	e->newim = 0;
	while (i < e->max_iter)
	{
		e->oldre = e->newre;
		e->oldim = e->newim;
		e->newre = e->oldre * e->oldre - e->oldim * e->oldim + e->cre;
		e->newim = 2 * fabs(e->oldre * e->oldim) + e->cim;
		if ((e->newre * e->newre + e->newim * e->newim) > 4)
			break ;
		i++;
	}
	e->iterations = i;
}
