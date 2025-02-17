/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:26:11 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 11:00:46 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	zoom(t_env *env, int event)
{
	double	x_center;
	double	y_center;

	x_center = (env->x_max + env->x_min) / 2.f;
	y_center = (env->y_max + env->y_min) / 2.f;
	if (event == 2)
	{
		env->x_max = x_center + (env->x_max - x_center) * 1.2;
		env->x_min = x_center + (env->x_min - x_center) * 1.2;
		env->y_max = y_center + (env->y_max - y_center) * 1.2;
		env->y_min = y_center + (env->y_min - y_center) * 1.2;
		env->moove *= 1.2;
	}
	else if (event == 1)
	{
		env->x_max = x_center + (env->x_max - x_center) / 1.2;
		env->x_min = x_center + (env->x_min - x_center) / 1.2;
		env->y_max = y_center + (env->y_max - y_center) / 1.2;
		env->y_min = y_center + (env->y_min - y_center) / 1.2;
		env->moove /= 1.2;
	}
}

void	zoom2(t_env *env, double of[2])
{
	int		x;
	int		y;
	double	f[2];

	mlx_mouse_get_pos(env->mlx->mlx, &x, &y);
	f[0] = (env->x_min * env->aspect) + ((x * (env->aspect * env->x_max
					- env->x_min * env->aspect)) / WIDTH);
	f[1] = env->y_min + (((HEIGHT - y) * (env->y_max - env->y_min))
			/ HEIGHT);
	env->x_min -= (f[0] - of[0]);
	env->x_max -= (f[0] - of[0]);
	env->y_min -= (f[1] - of[1]);
	env->y_max -= (f[1] - of[1]);
}

void	mouse_wheel_hook(int event, void *param)
{
	t_env	*env;
	int		ox;
	int		oy;
	double	of[2];

	env = (t_env *)param;
	mlx_mouse_get_pos(env->mlx->mlx, &ox, &oy);
	of[0] = (env->x_min * env->aspect) + ((ox * (env->aspect * env->x_max
					- env->x_min * env->aspect)) / WIDTH);
	of[1] = env->y_min + (((HEIGHT - oy) * (env->y_max - env->y_min))
			/ HEIGHT);
	zoom(env, event);
	zoom2(env, of);
	choose_fractal(env);
}
