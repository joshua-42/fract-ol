/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:43:13 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/14 00:50:03 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <fractol.h>

void	change_color(t_env *env)
{
	env->color_choise++;
	env->color_1 = (mlx_color){.rgba = 0x00000000};
	if (env->color_choise == 1)
		env->color_1 = (mlx_color){.rgba = 0xFF753B00};
	if (env->color_choise == 2)
		env->color_1 = (mlx_color){.rgba = 0x0055FF00};
	if (env->color_choise == 3)
		env->color_1 = (mlx_color){.rgba = 0xF0092100};
	if (env->color_choise == 4)
		env->color_1 = (mlx_color){.rgba = 0xBB09F000};
	if (env->color_choise == 5)
	{
		env->color_1 = (mlx_color){.rgba = 0x09F07600};
		env->color_choise = 0;
	}
}
