/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:43:12 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:01:02 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "mlx.h"
#include <fractol.h>

void	prep_julia(char **argv)
{
	t_env	*env;

	env = set_env();
	env->fractal = 1;
	env->c_r_julia = ft_atof(argv[2]);
	env->c_i_julia = ft_atof(argv[3]);
	set_mlx(env->mlx);
	print_param();
	draw_julia(env);
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
