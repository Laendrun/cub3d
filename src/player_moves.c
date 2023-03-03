/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:21:20 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 23:34:06 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_env * env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	if (env->map2d.px[(int)(env->player.pos.x + p_cos) + (int)(env->player.pos.y + p_sin) * env->map2d.width] == env->map.floor)
	{
		env->player.pos.x += p_cos;
		env->player.pos.y += p_sin;
	}
}

void	backward(t_env *env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	if (env->map2d.px[(int)(env->player.pos.x - p_cos) + (int)(env->player.pos.y - p_sin) * env->map2d.width] == env->map.floor)
	{
		env->player.pos.x -= p_cos;
		env->player.pos.y -= p_sin;
	}
	// printf("new_x: %f\nnew_y: %f\n", env->player.pos.x, env->player.pos.y);
}

void	rotate_cc(t_env *env)
{
	env->player.c_angle -= 3;
}

void	rotate_c(t_env *env)
{
	env->player.c_angle += 3;
}
