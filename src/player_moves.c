/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:21:20 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 23:16:23 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_env * env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	env->player.pos.x += p_cos;
	env->player.pos.y += p_sin;
}

void	backward(t_env *env)
{
	float	p_cos;
	float	p_sin;

	p_cos = cosf(degToRad(env->player.c_angle));
	p_sin = sinf(degToRad(env->player.c_angle));
	env->player.pos.x -= p_cos;
	env->player.pos.y -= p_sin;
	// printf("new_x: %f\nnew_y: %f\n", env->player.pos.x, env->player.pos.y);
}

void	rotate_cc(t_env *env)
{
	env->player.c_angle--;
}

void	rotate_c(t_env *env)
{
	env->player.c_angle++;
}
