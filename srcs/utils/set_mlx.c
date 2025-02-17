/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:15:54 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/13 15:22:44 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "mlx.h"
#include <fractol.h>

void	set_mlx(t_mlx *mlx)
{
	mlx_window_create_info	info;

	ft_memset(&info, 0, sizeof(mlx_window_create_info));
	info.title = "FRACTOL";
	info.width = WIDTH;
	info.height = HEIGHT;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, &info);
	mlx_set_fps_goal(mlx->mlx, 120);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
}
