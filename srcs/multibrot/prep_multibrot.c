/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_multibrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:13:21 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:01:20 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fractol.h>

void	prep_multibrot(int power)
{
	t_env	*env;

	env = set_env();
	env->fractal = 3;
	env->d = power;
	set_mlx(env->mlx);
	print_param();
	draw_multibrot(env);
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

bool	overflow(int num_over, int num, int sign, char *str)
{
	if (*str >= '0' && *str <= '9')
	{
		if (num_over * 10 + *str - '0' < num && *str && sign == 1)
			return (0);
		else if ((num_over * 10 + *str - '0') * sign > num * sign
			&& *str && sign == -1)
			return (0);
	}
	return (1);
}

bool	ft_strtoi(char *str)
{
	int	num;
	int	num_over;
	int	sign;

	num = 0;
	sign = 1;
	while ((unsigned int)*str - 8 < 6 || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while ((unsigned int)*str - 48 < 10)
	{
		num = num * 10 + *str - '0';
		num_over = num;
		str++;
		if (!overflow(num_over, num, sign, str))
			return (0);
	}
	return (1);
}

void	parse_multibrot(char *str)
{
	if (!*str || !ft_strtoi(str) || !check_num(str) || ft_atoi(str) <= 0)
	{
		write_error();
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(str) > 1000)
	{
		write(2, "do you want to blow up the pc?!?!\n", 34);
		exit(EXIT_FAILURE);
	}
	prep_multibrot(ft_atoi(str));
}
