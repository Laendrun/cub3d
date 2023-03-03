/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:20:32 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 17:42:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	touch_wall(t_env *env, t_v2 v)
{
	if (env->minimap.px[(int)(v.x + v.y * env->minimap.mm_width)] == WALL_COLOR)
		return (1);
	if (env->minimap.px[(int)((v.x - 1) + v.y * env->minimap.mm_width)] == WALL_COLOR)
		return (1);
	if (env->minimap.px[(int)((v.x + 1) + v.y * env->minimap.mm_width)] == WALL_COLOR)
		return (1);
	if (env->minimap.px[(int)(v.x + (v.y - 1) * env->minimap.mm_width)] == WALL_COLOR)
		return (1);
	if (env->minimap.px[(int)(v.x + (v.y + 1) * env->minimap.mm_width)] == WALL_COLOR)
		return (1);
	return (0);
}

void	set_distance(t_env *env, t_v2 player, t_v2 wall)
{
	env->dist = sqrt(pow((player.x - wall.x), 2) + pow((player.y - wall.y), 2));
}

void	cast_ray(t_env *env)
{
	size_t	i;
	t_v2	w_p;

	w_p = (t_v2){0, 0};
	i = 0;
	if (env->player.c_dir == 'N')
	{
		while (!touch_wall(env, (t_v2){env->player.pos.x, env->player.pos.y - i}) && distance(env->player.pos, (t_v2){env->player.pos.x, env->player.pos.y - i}) < env->minimap.mm_height / 2)
			i++;
		w_p = (t_v2){env->player.pos.x, env->player.pos.y - i};
		ft_draw_line(env, (t_v4){env->player.pos.x, env->player.pos.y, w_p.x, w_p.y}, 0xFF00FF, 2);
		put_px(env, w_p, 0xFF0000, 2);
	}
	else if (env->player.c_dir == 'E')
	{
		while (!touch_wall(env, (t_v2){env->player.pos.x + i, env->player.pos.y}))
			i++;
		w_p = (t_v2){env->player.pos.x + i, env->player.pos.y};
		ft_draw_line(env, (t_v4){env->player.pos.x, env->player.pos.y, w_p.x, w_p.y}, 0xFF00FF, 2);
		put_px(env, w_p, 0xFF0000, 2);
	}
	else if (env->player.c_dir == 'S')
	{
		while (!touch_wall(env, (t_v2){env->player.pos.x, env->player.pos.y + i}))
			i++;
		w_p = (t_v2){env->player.pos.x, env->player.pos.y + i};
		ft_draw_line(env, (t_v4){env->player.pos.x, env->player.pos.y, w_p.x, w_p.y}, 0xFF00FF, 2);
		put_px(env, w_p, 0xFF0000, 2);
	}
	else if (env->player.c_dir == 'W')
	{
		while (!touch_wall(env, (t_v2){env->player.pos.x - i, env->player.pos.y}))
			i++;
		w_p = (t_v2){env->player.pos.x - i, env->player.pos.y};
		ft_draw_line(env, (t_v4){env->player.pos.x, env->player.pos.y, w_p.x, w_p.y}, 0xFF00FF, 2);
		put_px(env, w_p, 0xFF0000, 2);
	}
	set_distance(env, env->player.pos, w_p);
}
