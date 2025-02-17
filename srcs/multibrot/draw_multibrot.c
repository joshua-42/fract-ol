/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multibrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:31:09 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 15:47:43 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

mlx_color	calcul_pixel_multi(double x, double y, t_env *env)
{
	int		it;
	double	r;
	double	theta;
	double	r_d;

	it = 0;
	env->c_r = (env->x_min * env->aspect) + ((x * (env->aspect * env->x_max
					- env->x_min * env->aspect)) / WIDTH);
	env->c_i = env->y_min + (((HEIGHT - y) * (env->y_max - env->y_min))
			/ HEIGHT);
	env->z_i = 0;
	env->z_r = 0;
	while ((env->z_r * env->z_r + env->z_i * env->z_i) <= 4 && it < env->max_it)
	{
		r = sqrt(env->z_r * env->z_r + env->z_i * env->z_i);
		theta = atan2(env->z_i, env->z_r);
		r_d = pow(r, env->d);
		env->z_r = r_d * cos(env->d * theta) + env->c_r;
		env->z_i = r_d * sin(env->d * theta) + env->c_i;
		it++;
	}
	if (it == env->max_it)
		return ((mlx_color){.rgba = 0x00000000});
	else
		return (color(it, env));
}

void	draw_multibrot(t_env *env)
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
				y, (mlx_color)calcul_pixel_multi(x, y, env));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->mlx->img, 0, 0);
}
