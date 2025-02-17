/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:03:40 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/15 19:03:06 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <fractol.h>
#include <sys/types.h>

u_int32_t	log_of_log(int it, t_env *env)
{
	return (it - log(log(env->z_r * env->z_r + env->z_i * env->z_i)) / log(2));
}

mlx_color	color(int it, t_env *env)
{
	u_int32_t	test;

	test = 0;
	test += (env->color_1.r << 24);
	test += (env->color_1.g << 16);
	test += (env->color_1.b << 8);
	test += env->color_1.a;
	test += (unsigned int) log_of_log(it, env);
	test += (unsigned int) log_of_log(it, env);
	test += (unsigned int) log_of_log(it, env);
	return ((mlx_color){.rgba = test});
}
