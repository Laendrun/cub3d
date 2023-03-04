/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:27:31 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:28:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_pt(t_env *env, t_v2 v, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			env->map2d.px[(int)((v.x + i) + (v.y + j) * \
				(env->map.width * SIZE))] = color;
			j++;
		}
		i++;
	}
}

void	fill_map2d(t_env *env, t_v2 v)
{
	if (env->mapc[(int)v.x + (int)v.y * env->map.width] == '1')
		fill_pt(env, (t_v2){(int)v.x * SIZE, (int)v.y * SIZE}, WALL);
	if (env->mapc[(int)v.x + (int)v.y * env->map.width] == '0')
		fill_pt(env, (t_v2){(int)v.x * SIZE, (int)v.y * SIZE}, env->map.floor);
	if (env->mapc[(int)v.x + (int)v.y * env->map.width] == ' ')
		fill_pt(env, (t_v2){(int)v.x * SIZE, (int)v.y * SIZE}, 0x0);
}

int	set_start(t_v2 v, t_env *env)
{
	int	tmp;

	if (env->player.pos.x != 0 || env->player.pos.y != 0)
		return (puterr("Error\nMultiple start position found on map.", NULL));
	env->player.pos.x = v.x * SIZE + SIZE / 2;
	env->player.pos.y = v.y * SIZE + SIZE / 2;
	tmp = env->mapc[(int)(v.x + v.y * env->map.width)];
	env->mapc[(int)(v.x + v.y * env->map.width)] = '0';
	if (tmp == 'N')
		env->player.angle = 270;
	else if (tmp == 'E')
		env->player.angle = 0;
	else if (tmp == 'S')
		env->player.angle = 90;
	else if (tmp == 'W')
		env->player.angle = 180;
	return (0);
}
