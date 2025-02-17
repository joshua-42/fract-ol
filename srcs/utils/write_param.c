/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:40:31 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:37 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <fractol.h>

void	print_param2(void)
{
	ft_printf("%s\n", "|        -Scroll with moose whell to zomm         |");
	ft_printf("%s\n", "|        -Press ` key to swap between fractal     |");
	ft_printf("%s\n", "|        -Press shift to change color             |");
	ft_printf("%s\n", "|        -Press echap to leave the program        |");
	ft_printf("%s\n", "|        -Click on the crose to leave the program |");
	ft_printf("%s\n", "|                                                 |");
	ft_printf("%s\n", "---------------------------------------------------");
}

void	print_param(void)
{
	ft_printf("%s\n", "---------------------------------------------------");
	ft_printf("%s\n", "|                                                 |");
	ft_printf("%s\n", "|    Fractal choise :                             |");
	ft_printf("%s\n", "|        -Mandelbrot with no argument             |");
	ft_printf("%s\n", "|        -Julia with two floating numbers         |");
	ft_printf("%s\n", "|        -Burningship with no argument            |");
	ft_printf("%s\n", "|        -Multibrot with one number between       |");
	ft_printf("%s\n", "|         0 and 1000                              |");
	ft_printf("%s\n", "|                                                 |");
	ft_printf("%s\n", "---------------------------------------------------");
	ft_printf("%s\n", "|                                                 |");
	ft_printf("%s\n", "|    Features :                                   |");
	ft_printf("%s\n", "|        -Press q to put max iter on 5000         |");
	ft_printf("%s\n", "|        -Press r to reset number of iter         |");
	ft_printf("%s\n", "|        -Press s to save your position           |");
	ft_printf("%s\n", "|        -Press b to go on the position you save  |");
	ft_printf("%s\n", "|        -Press enter to reset you fractal bound  |");
	ft_printf("%s\n", "|        -Press +/- on the numeric keypas         |");
	ft_printf("%s\n", "|         to increase or decrease iter num        |");
	ft_printf("%s\n", "|        -Press -/+ on the alphanumerics keys     |");
	ft_printf("%s\n", "|         to increase or decrease the number      |");
	ft_printf("%s\n", "|         of multibrot (only work on multibrot)   |");
	ft_printf("%s\n", "|        -Press arrows keys to moove in           |");
	ft_printf("%s\n", "|         in the fractal                          |");
	print_param2();
}
