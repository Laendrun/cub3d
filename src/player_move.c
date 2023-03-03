/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:11:40 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 15:32:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	player_touch_wall(t_env *env, int x, int y)
{
	// don't forget that player is drawn from -PLAYER_SIZE/2 and ends at PLAYER_SIZE/2

	int	i;
	int	j;

	i = - PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = - PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			if (env->minimap.px[(int)((env->player.pos.x + i + x) + (env->player.pos.y + j + y) * env->minimap.mm_width)] == WALL_COLOR)
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
	if (env->player.c_dir == 'N' && !player_touch_wall(env, 0, -1))
		env->player.pos.y--;
	else if (env->player.c_dir == 'S' && !player_touch_wall(env, 0, 1))
		env->player.pos.y++;
	else if (env->player.c_dir == 'E' && !player_touch_wall(env, 1, 0))
		env->player.pos.x++;
	else if (env->player.c_dir == 'W' && !player_touch_wall(env, -1, 0))
		env->player.pos.x--;
}

void	backward(t_env *env)
{
	if (env->player.c_dir == 'N' && !player_touch_wall(env, 0, 1))
		env->player.pos.y++;
	else if (env->player.c_dir == 'S' && !player_touch_wall(env, 0, -1))
		env->player.pos.y--;
	else if (env->player.c_dir == 'E' && !player_touch_wall(env, -1, 0))
		env->player.pos.x--;
	else if (env->player.c_dir == 'W' && !player_touch_wall(env, 1, 0))
		env->player.pos.x++;
}

void	rotate_cc(t_env *env)
{
	if (env->player.c_dir == 'N')
		env->player.c_dir = 'W';
	else if (env->player.c_dir == 'W')
		env->player.c_dir = 'S';
	else if (env->player.c_dir == 'S')
		env->player.c_dir = 'E';
	else if (env->player.c_dir == 'E')
		env->player.c_dir = 'N';
}

void	rotate_c(t_env *env)
{
	if (env->player.c_dir == 'N')
		env->player.c_dir = 'E';
	else if (env->player.c_dir == 'E')
		env->player.c_dir = 'S';
	else if (env->player.c_dir == 'S')
		env->player.c_dir = 'W';
	else if (env->player.c_dir == 'W')
		env->player.c_dir = 'N';
}