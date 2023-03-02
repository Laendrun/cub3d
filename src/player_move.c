/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:11:40 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 21:28:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	backward(t_env *env)
{
	if (env->player.c_dir == 'N')
		env->player.pos.y++;
	else if (env->player.c_dir == 'S')
		env->player.pos.y--;
	else if (env->player.c_dir == 'E')
		env->player.pos.x--;
	else if (env->player.c_dir == 'W')
		env->player.pos.x++;
}

void	forward(t_env * env)
{
	if (env->player.c_dir == 'N')
		env->player.pos.y--;
	else if (env->player.c_dir == 'S')
		env->player.pos.y++;
	else if (env->player.c_dir == 'E')
		env->player.pos.x++;
	else if (env->player.c_dir == 'W')
		env->player.pos.x--;
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