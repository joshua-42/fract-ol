/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_julia_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:33:58 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/17 15:52:50 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <fractol.h>
#include <unistd.h>

bool	is_dot_or_come(int c)
{
	if (c == 44 || c == 46)
		return (1);
	return (0);
}

bool	check_arg(char *str)
{
	if (!ft_issign(*str) && ((ft_issign(*str) && !ft_isdigit(*str + 1))
			&& !ft_isdigit(*str)) && !is_dot_or_come(*str))
		return (0);
	return (1);
}

bool	check_num(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (!check_arg(str))
		return (0);
	if (ft_issign(*str))
		str++;
	while (ft_isdigit(*str))
	{
		str++;
	}
	if (is_dot_or_come(*str))
		str++;
	while (ft_isdigit(*str))
	{
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

void	parsing_julia_args(char **argv)
{
	if ((ft_strlen(argv[2]) != 0 && check_num(argv[2]))
		&& (ft_strlen(argv[3]) != 0 && check_num(argv[3])))
	{
		prep_julia(argv);
	}
	else
		write_error();
}
