/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:31 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 16:11:05 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <fractol.h>

void	choose_fractal(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->win,
		(mlx_color){.rgba = 0x00000000});
	if (env->fractal == 0)
		draw_mandelbrot(env);
	if (env->fractal == 1)
		draw_julia(env);
	if (env->fractal == 2)
		draw_burningship(env);
	if (env->fractal == 3)
		draw_multibrot(env);
}

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
}

void	change_bounds(t_env *env, int option)
{
	if (option == 1)
	{
		env->y_max += env->moove;
		env->y_min += env->moove;
	}
	else if (option == 2)
	{
		env->y_max -= env->moove;
		env->y_min -= env->moove;
	}
	else if (option == 3)
	{
		env->x_max -= env->moove;
		env->x_min -= env->moove;
	}
	else if (option == 4)
	{
		env->x_max += env->moove;
		env->x_min += env->moove;
	}
}

void	check_moove(t_env *env, int event)
{
	if (event >= 79 && event <= 82)
	{
		if (event == 82)
			change_bounds(env, 1);
		if (event == 81)
			change_bounds(env, 2);
		if (event == 80)
			change_bounds(env, 3);
		if (event == 79)
			change_bounds(env, 4);
	}
}

void	key_hook(int event, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (event == 53)
	{
		env->fractal++;
		if (env->fractal == 4)
			env->fractal = 0;
	}
	if (event == 41)
	{
		mlx_loop_end(env->mlx->mlx);
		return ;
	}
	if (event == 20)
		env->max_it = 10000;
	save(env, event);
	reset(env, event);
	check_moove(env, event);
	iter(env, event);
	if (event == 225)
		change_color(env);
	choose_fractal(env);
}
