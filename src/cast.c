/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 23:18:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_env *env)
{
	float	ray_angle;
	size_t	ray_count;
	float	ray_cos;
	float	ray_sin;
	float	ray_angle_incr;
	int		wall;
	float	wall_h;
	float	dist;
	t_v2	ray;

	ray_angle = env->player.c_angle - env->player.halffov;
	ray_angle_incr = env->player.fov / WIN_W;
	ray_count = 0;
	while (ray_count < WIN_W)
	{
		ray.x = env->player.pos.x;
		ray.y = env->player.pos.y;
		ray_cos = cosf(degToRad(ray_angle));
		ray_sin = sinf(degToRad(ray_angle));
		wall = env->map.floor;
		while (wall == env->map.floor)
		{
			ray.x += ray_cos;
			ray.y += ray_sin;
			wall = env->map2d.px[(int)ray.x + (int)ray.y * env->map2d.width];
		}
		draw_line(env, (t_v4){env->player.pos.x, env->player.pos.y, ray.x, ray.y}, 0xFF00FF, 2);
		put_px(env, (t_v2){ray.x, ray.y}, 0xFF0000, 2);
		dist = sqrt(pow(env->player.pos.x - ray.x, 2) + pow(env->player.pos.y - ray.y, 2));
		wall_h = (WIN_H * 5) / dist;
		// printf("wall h: %f\n", wall_h);
		draw_line(env, (t_v4){ray_count, (WIN_H / 2.0) - (wall_h), ray_count, (WIN_H / 2.0) + (wall_h)}, WALL, 1);
		ray_angle += ray_angle_incr;
		ray_count++;
	}
}

/*
drawLine(rayCount, 0, rayCount, data.screen.halfHeight - wallHeight, "cyan"); // ceiling
drawLine(rayCount, data.screen.halfHeight - wallHeight, rayCount, data.screen.halfHeight + wallHeight, "red"); // wall
drawLine(rayCount, data.screen.halfHeight + wallHeight, rayCount, data.screen.height, "green"); // floor
*/