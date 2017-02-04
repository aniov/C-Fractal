/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:10:40 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 16:19:42 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_menu_info_0(t_env *e, int *y)
{
	*y = 0;
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 10, C_CRIM, "MENU:");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 30, C_SGRAY, S_ZOOM);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "mouse scroll");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_MOVE);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "arrow keys");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_RIMG);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "F1");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_MOUSE);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "L");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_ITER);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "+/-");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, "Colors:");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_RGB);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "7 /4 /1");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, S_CRANGE);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "8 / 2");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 20, C_SGRAY, "Fractals:");
	mlx_string_put(e->mlx, e->win, WIN_W + 160, *y, C_DSALMON, "F2 / F3 / F4");
	mlx_string_put(e->mlx, e->win, WIN_W + 10, *y += 100, C_SGRAY, S2_ITER);
}

void		print_menu_info(t_env *e)
{
	int		y;
	char	*str;
	char	s[40];

	print_menu_info_0(e, &y);
	str = ft_itoa((int)e->max_iter);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, y, C_DSALMON, str);
	mlx_string_put(e->mlx, e->win, WIN_W + 10, y += 20, C_SGRAY,
			"c = cRe + cIm");
	mlx_string_put(e->mlx, e->win, WIN_W + 160, y, C_DSALMON, "cRe=");
	sprintf(s, "%f", e->cre / e->zoom);
	mlx_string_put(e->mlx, e->win, WIN_W + 200, y, C_DSALMON, s);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, y += 20, C_DSALMON, "cIm=");
	sprintf(s, "%f", e->cim / e->zoom);
	mlx_string_put(e->mlx, e->win, WIN_W + 200, y, C_DSALMON, s);
	mlx_string_put(e->mlx, e->win, WIN_W + 10, y += 20, C_SGRAY, "zoom:");
	sprintf(s, "%.Lf", (long double)e->zoom);
	mlx_string_put(e->mlx, e->win, WIN_W + 160, y, C_DSALMON, s);
	mlx_string_put(e->mlx, e->win, WIN_W + 10, y += 20, C_SGRAY,
			"mouse Lock:");
	mlx_string_put(e->mlx, e->win, WIN_W + 160, y, C_DSALMON,
			(e->lock) ? "ON" : "OFF");
}
