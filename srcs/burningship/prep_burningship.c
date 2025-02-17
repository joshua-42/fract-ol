/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:13:21 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:00:41 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	prep_burningship(void)
{
	t_env	*env;

	env = set_env();
	env->fractal = 2;
	set_mlx(env->mlx);
	print_param();
	draw_burningship(env);
	mlx_on_event(env->mlx->mlx, env->mlx->win, MLX_KEYDOWN, key_hook, env);
	mlx_on_event(env->mlx->mlx, env->mlx->win, MLX_WINDOW_EVENT,
		window_hook, env->mlx->mlx);
	mlx_on_event(env->mlx->mlx, env->mlx->win, MLX_MOUSEWHEEL,
		mouse_wheel_hook, env);
	mlx_loop(env->mlx->mlx);
	mlx_destroy_image(env->mlx->mlx, env->mlx->img);
	mlx_destroy_window(env->mlx->mlx, env->mlx->win);
	mlx_destroy_context(env->mlx->mlx);
	free(env->mlx);
	free(env);
}
