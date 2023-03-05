/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:21:20 by saeby             #+#    #+#             */
/*   Updated: 2023/03/05 12:29:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_env *env)
{
	float	p_cos;
	float	p_sin;
	float	new_x;
	float	new_y;

	p_cos = cosf(degToRad(env->player.angle));
	p_sin = sinf(degToRad(env->player.angle));
	new_x = env->player.pos.x + p_cos * 2;
	new_y = env->player.pos.y + p_sin * 2;
	if (env->map2d.px[(int)new_x + (int)new_y * env->map2d.width] == env->map.floor)
	{
		env->player.pos.x = new_x;
		env->player.pos.y = new_y;
	}
}

void	backward(t_env *env)
{
	float	p_cos;
	float	p_sin;
	float	new_x;
	float	new_y;

	p_cos = cosf(degToRad(env->player.angle));
	p_sin = sinf(degToRad(env->player.angle));
	new_x = env->player.pos.x - p_cos * 2;
	new_y = env->player.pos.y - p_sin * 2;
	if (env->map2d.px[(int)new_x + (int)new_y * env->map2d.width] == env->map.floor)
	{
		env->player.pos.x = new_x;
		env->player.pos.y = new_y;
	}
}

void	rotate_cc(t_env *env)
{
	env->player.angle -= 3;
}

void	rotate_c(t_env *env)
{
	env->player.angle += 3;
}
