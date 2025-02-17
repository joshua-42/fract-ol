/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:47:33 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:35 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FREE_H
# define FT_FREE_H

# include <stdlib.h>

void	ft_free(char **str);
void	free_cleanup_char(char **str);

#endif
