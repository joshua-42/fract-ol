/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:31:09 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 11:00:53 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

mlx_color	calcul_pixel_bur(double x, double y, t_env *env)
{
	int		it;
	double	tmp;

	it = 0;
	env->c_r = (env->x_min * env->aspect) + ((x * (env->aspect * env->x_max
					- env->x_min * env->aspect)) / WIDTH);
	env->c_i = env->y_min + (((HEIGHT - y) * (env->y_max - env->y_min))
			/ HEIGHT);
	env->z_i = 0;
	env->z_r = 0;
	while ((env->z_r * env->z_r + env->z_i * env->z_i) <= 4 && it < env->max_it)
	{
		tmp = env->z_r;
		env->z_r = ((env->z_r * env->z_r) - (env->z_i * env->z_i) + env->c_r);
		env->z_i = (2 * ft_abs(env->z_i * tmp) + env->c_i);
		it++;
	}
	if (it == env->max_it)
		return ((mlx_color){.rgba = 0x00000000});
	else
		return (color(it, env));
}

void	draw_burningship(t_env *env)
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
				y, (mlx_color)calcul_pixel_bur(x, y, env));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->mlx->img, 0, 0);
}
