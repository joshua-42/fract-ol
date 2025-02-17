/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:26:45 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 14:52:42 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

int	main(int argc, char **argv)
{
	if (argc != 1 && argc < 5)
	{
		if ((ft_strncmp(argv[1], "mandelbrot", 10) == 0
				|| ft_strncmp(argv[1], "Mandelbrot", 10) == 0) && argc == 2)
			prep_mandelbrot();
		else if ((ft_strncmp(argv[1], "julia", 5) == 0
				|| ft_strncmp(argv[1], "Julia", 5) == 0) && argc == 4)
			parsing_julia_args(argv);
		else if ((ft_strncmp(argv[1], "burningship", 11) == 0
				|| ft_strncmp(argv[1], "Burningship", 11) == 0) && argc == 2)
			prep_burningship();
		else if ((ft_strncmp(argv[1], "multibrot", 9) == 0
				|| ft_strncmp(argv[1], "Multibrot", 9) == 0) && argc == 3)
			parse_multibrot(argv[2]);
		else
			write_error();
	}
	else
		write_error();
}
