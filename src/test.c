/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:22:42 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 18:35:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ray_casting(t_env *env)
{
	float	angle_increment = FOV / WIN_W;
	float	ray_angle = env->player.c_angle - FOV / 2;
	int		ray_count = 0;
	t_v2	ray;
	float	rayCos;
	float	raySin;
	float	dist;
	float	w_height;

	while (ray_count < WIN_W)
	{
		//printf("current angle: %f\n", env->player.c_angle);
		ray.x = env->player.pos.x;
		ray.y = env->player.pos.y;
		rayCos = cosf(degToRad(ray_angle));
		raySin = sinf(degToRad(ray_angle));
		while (!touch_wall(env, ray))
		{
			ray.x += rayCos;
			ray.y += raySin;
		}
		dist = distance(env->player.pos, ray);
		w_height = (WIN_H / 2) / dist;
		ft_draw_line(env, (t_v4){ray_count, (WIN_H / 2) - w_height / 2, ray_count, (WIN_H / 2) + w_height / 2}, WALL_COLOR, 1);
		ray_angle += angle_increment;
		ray_count++;
	}
}


// !touch_wall(env, (t_v2){env->player.pos.x - i, env->player.pos.y})
/*
// Draw
drawLine(rayCount, 0, rayCount, data.screen.halfHeight - wallHeight, "cyan");
drawLine(rayCount, data.screen.halfHeight - wallHeight, rayCount, data.screen.halfHeight + wallHeight, "red");
drawLine(rayCount, data.screen.halfHeight + wallHeight, rayCount, data.screen.height, "green");
*/