/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:36:37 by jodougla          #+#    #+#             */
/*   Updated: 2025/05/14 10:40:40 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	write_error(void)
{
	write(2, "Error enter one of this name\n", 29);
	write(2, "-Mandelbrot\n", 12);
	write(2, "-Julia with two float number\n", 29);
	write(2, "-Burningship\n", 13);
	write(2, "-Multibrot with one integer\n", 28);
}
