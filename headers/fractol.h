/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:20:49 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 17:00:28 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libft.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define HEIGHT 900.f
# define WIDTH 900.f
# define X_MIN -2.f
# define Y_MIN -2.f
# define Y_MAX 2.f
# define X_MAX 2.f

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_mlx;

typedef struct s_env
{
	struct s_mlx	*mlx;
	int				fractal;
	double			z_r;
	double			z_i;
	double			c_r_julia;
	double			c_i_julia;
	double			c_r;
	double			c_i;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	double			save_moove;
	double			save_x_max;
	double			save_x_min;
	double			save_y_max;
	double			save_y_min;
	double			x;
	double			y;
	double			zoom;
	int				color_choise;
	mlx_color		color_1;
	int				max_it;
	double			aspect;
	double			moove;
	int				d;
}	t_env;

void		free_all(t_env *env);
void		write_error(void);
void		parsing(char *name);
void		draw_mandelbrot(t_env *env);
t_env		*set_env(void);
void		set_mlx(t_mlx *mlx);
void		prep_mandelbrot(void);
void		mouse_wheel_hook(int event, void *param);
void		window_hook(int event, void *param);
void		key_hook(int key, void *mlx);
void		parsing_julia_args(char **argv);
void		draw_julia(t_env *env);
void		prep_julia(char **argv);
void		choose_fractal(t_env *env);
int			hook(void *param);
mlx_color	color(int it, t_env *env);
void		change_color(t_env *env);
void		mouse_wheel_hook(int event, void *param);
void		draw_burningship(t_env *env);
void		prep_burningship(void);
void		save(t_env *env, int event);
void		reset(t_env *env, int event);
void		iter(t_env *env, int event);
void		draw_multibrot(t_env *env);
void		parse_multibrot(char *str);
bool		check_num(char *str);
void		print_param(void);

#endif
