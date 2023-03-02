/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:14:28 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 19:56:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	space_around(t_v2 v, t_env *env)
{
	// printf("checking x: %zu, y: %zu\n", v.x, v.y);

	if (v.x == 0)
	{
		// UP DOWN RIGHT
		if (env->mapc[v.x + (v.y - 1) * env->map.width] == ' ' || \
			env->mapc[v.x + (v.y + 1) * env->map.width] == ' ' || \
			env->mapc[(v.x + 1) + v.y * env->map.width] == ' ')
			return (1);
	}
	else if (v.x == env->map.width - 1)
	{
		// UP DOWN LEFT
		if (env->mapc[v.x + (v.y - 1) * env->map.width] == ' ' || \
			env->mapc[v.x + (v.y + 1) * env->map.width] == ' ' || \
			env->mapc[(v.x - 1) + v.y * env->map.width] == ' ')
			return (1);
	}
	else
	{
		// UP DOWN LEFT RIGHT
		if (env->mapc[v.x + (v.y - 1) * env->map.width] == ' ' || \
			env->mapc[v.x + (v.y + 1) * env->map.width] == ' ' || \
			env->mapc[(v.x - 1) + v.y * env->map.width] == ' ' || \
			env->mapc[(v.x + 1) + v.y * env->map.width] == ' ')
			return (1);
	}
	return (0);
}

int	check_map(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	// first line should be either '1' or ' ' but not '0'
	while (x < env->map.width)
	{
		if (env->mapc[x + y * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	x = 0;
	// last line should be either '1' or ' ' but not '0'
	while (x < env->map.width)
	{
		if (env->mapc[x + (env->map.height - 1) * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	// for all other lines, '0' should not be next to a ' ' (UP, DOWN, LEFT, RIGHT)
	y = 1;
	while (y < env->map.height - 1) // -1 'cause I don't want to check the last line again
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '0')
				if (space_around((t_v2){x, y}, env))
					return (puterr("Error\nMap not enclosed in walls.", NULL));
			x++;
		}
		y++;
	}
	return (0);
}