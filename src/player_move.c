/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:11:40 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 18:32:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	player_touch_wall(t_env *env, int x, int y)
{
	// don't forget that player is drawn from -PLAYER_SIZE/2 and ends at PLAYER_SIZE/2

	float	i;
	float	j;

	i = - PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = - PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			if (env->minimap.px[(int)((x + j) + (y + i) * env->minimap.mm_width)] == WALL_COLOR)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// check wall collisions and out of screen moves...

void	forward(t_env * env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	if (!player_touch_wall(env, env->player.pos.x + p_cos, env->player.pos.y + p_sin))
	{
		env->player.pos.x += p_cos;
		env->player.pos.y += p_sin;

	}
	printf("new_x: %f\nnew_y: %f\n", env->player.pos.x, env->player.pos.y);
}

void	backward(t_env *env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	if (!player_touch_wall(env, env->player.pos.x - p_cos, env->player.pos.y - p_sin))
	{
		env->player.pos.x -= p_cos;
		env->player.pos.y -= p_sin;
	}
	printf("new_x: %f\nnew_y: %f\n", env->player.pos.x, env->player.pos.y);
}

void	rotate_cc(t_env *env)
{
	env->player.c_angle--;
}

void	rotate_c(t_env *env)
{
	env->player.c_angle++;
}