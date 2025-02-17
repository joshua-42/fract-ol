/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:33:13 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 14:33:06 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	set_color(t_env *env)
{
	env->color_1 = (mlx_color){.rgba = 0xFF753B00};
}

void	set_env2(t_env *env)
{
	env->y = 0;
	env->max_it = 50;
	set_color(env);
	env->color_choise = 1;
	env->x_max = 1;
	env->x_min = -1;
	env->y_max = 1;
	env->y_min = -1;
	env->aspect = WIDTH / HEIGHT;
	env->moove = 0.05;
	env->c_r_julia = 0.285;
	env->c_i_julia = 0.01;
	env->d = 3;
}

t_env	*set_env(void)
{
	t_env	*env;
	t_mlx	*mlx;

	env = malloc(sizeof(t_env));
	if (!env)
	{
		write(2, "malloc failed\n", 14);
		exit (EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		free(env);
		write(2, "malloc failed\n", 14);
		exit (EXIT_FAILURE);
	}
	env->fractal = 0;
	env->mlx = mlx;
	env->z_r = 0;
	env->z_i = 0;
	env->c_r = 0;
	env->c_i = 0;
	env->x = 0;
	set_env2(env);
	return (env);
}
