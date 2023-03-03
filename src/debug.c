/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:03:16 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 21:03:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			ft_printf("%c", env->mapc[x + y * env->map.width]);
			x++;
		}
		y++;
		ft_printf("\n");
	}
}