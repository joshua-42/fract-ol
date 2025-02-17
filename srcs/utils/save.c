/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:54:10 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/15 18:58:55 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	save(t_env *env, int event)
{
	if (event == 22)
	{
		env->save_moove = env->moove;
		env->save_x_max = env->x_max;
		env->save_x_min = env->x_min;
		env->save_y_max = env->y_max;
		env->save_y_min = env->y_min;
	}
	if (event == 5)
	{
		env->moove = env->save_moove;
		env->x_max = env->save_x_max;
		env->x_min = env->save_x_min;
		env->y_max = env->save_y_max;
		env->y_min = env->save_y_min;
	}
}
