/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:41:01 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/22 15:41:12 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_fractol(t_env *e, char *std)
{
	if (std[0] == 'J')
	{
		e->f = julia_set;
		e->fract_set = 'J';
	}
	else if (std[0] == 'M')
	{
		e->f = mandelbrot_set;
		e->fract_set = 'M';
	}
	else if (std[0] == 'B')
	{
		e->f = burning_ship;
		e->fract_set = 'B';
	}
	ini_enviroment(e);
	create_window(e);
	return ;
}

void	print_menu(void)
{
	ft_putstr("MENU:\nUse argument\n");
	ft_putstr("\t'J': for Julia\n\t'M': for Mondelbort\n");
	ft_putstr("\t'B': for Burning ship\n");
}

void	read_input(int argc, char **argv)
{
	t_env e;

	if (argc != 2 || (ft_strcmp(JULIA, argv[1])
				&& ft_strcmp(MANDELBROT, argv[1])
				&& ft_strcmp(BURN_SHIP, argv[1])))
	{
		print_menu();
		exit(0);
	}
	else
		start_fractol(&e, argv[1]);
}

int		main(int argc, char **argv)
{
	read_input(argc, argv);
	return (0);
}
