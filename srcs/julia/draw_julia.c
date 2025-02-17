/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:52:14 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/15 19:27:02 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

mlx_color	calcul_julia(t_env *env, double x, double y)
{
	int		it;
	double	tmp;

	it = 0;
	tmp = 0;
	env->z_r = (env->x_min * env->aspect) + ((x * (env->aspect * env->x_max
					- env->x_min * env->aspect)) / WIDTH);
	env->z_i = env->y_min + (((HEIGHT - y) * (env->y_max - env->y_min))
			/ HEIGHT);
	while ((env->z_r * env->z_r + env->z_i * env->z_i) <= 4 && it < env->max_it)
	{
		tmp = env->z_r;
		env->z_r = ((env->z_r * env->z_r) - (env->z_i * env->z_i)
				+ env->c_r_julia);
		env->z_i = (2 * tmp * env->z_i + env->c_i_julia);
		it++;
	}
	if (it == env->max_it)
		return ((mlx_color){.rgba = 0x00000000});
	else
		return (color(it, env));
}

void	draw_julia(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(env->mlx->mlx, env->mlx->img, x,
				y, calcul_julia(env, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->mlx->img, 0, 0);
}
