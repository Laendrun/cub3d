/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:21:33 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:21:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_bottom(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (x < env->map.width)
	{
		if (env->mapc[x + y * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	x = 0;
	while (x < env->map.width)
	{
		if (env->mapc[x + (env->map.height - 1) * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	return (0);
}

int	check_map(t_env *env)
{
	size_t	x;
	size_t	y;

	if (check_top_bottom(env))
		return (1);
	y = 1;
	while (y < env->map.height - 1)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '0')
				if (space_around((t_v2){x, y}, env))
					return (puterr("Error\nMap not enclosed in walls.", NULL));
			if (is_dir(env->mapc[x + y * env->map.width]))
				if (set_start((t_v2){x, y}, env))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
