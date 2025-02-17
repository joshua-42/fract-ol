/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:59:44 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:10:24 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	reset(t_env *env, int event)
{
	if (event == 40)
	{
		env->moove = 0.05;
		env->x_max = 1;
		env->x_min = -1;
		env->y_max = 1;
		env->y_min = -1;
	}
}

void	iter(t_env *env, int event)
{
	if (event == 21)
		env->max_it = 50;
	if (event == 87)
		env->max_it += 5;
	if (event == 86)
		env->max_it -= 5;
	if (event == 46 && env->fractal == 3 && env->d != 1000)
		env->d += 1;
	if (event == 45 && env->fractal == 3 && env->d != 1)
		env->d -= 1;
}
