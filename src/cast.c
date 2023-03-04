/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 14:41:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ray_pos(t_ray *ray, t_env *env)
{
	ray->wall = env->map.floor;
	while (ray->wall == env->map.floor)
	{
		ray->pos.x += ray->cos;
		ray->pos.y += ray->sin;
		ray->wall = env->map2d.px[(int)ray->pos.x + \
			(int)ray->pos.y * env->map2d.width];
	}
}

static void	render_slice(t_ray *ray, t_env *env)
{
	draw_line(env, (t_v4){ray->count, 0, ray->count, (WIN_H / 2) - \
				ray->wall_h}, env->map.ceiling);
	draw_line(env, (t_v4){ray->count, (WIN_H / 2.0) - ray->wall_h, \
				ray->count, (WIN_H / 2.0) + ray->wall_h}, \
				shade(env->map.wall, ray->dist));
	draw_line(env, (t_v4){ray->count, (WIN_H / 2.0) + ray->wall_h, \
				ray->count, (WIN_H / 2.0) + ray->wall_h}, \
				env->map.floor);
}

void	raycasting(t_env *env)
{
	t_ray	ray;

	ray.angle = env->player.angle - env->player.halffov;
	env->raycast.a_i = env->player.fov / WIN_W;
	ray.count = 0;
	while (ray.count < WIN_W)
	{
		ray.pos = env->player.pos;
		ray.cos = cosf(degToRad(ray.angle));
		ray.sin = sinf(degToRad(ray.angle));
		set_ray_pos(&ray, env);
		ray.dist = sqrt(pow(env->player.pos.x - ray.pos.x, 2) + \
						pow(env->player.pos.y - ray.pos.y, 2));
		ray.dist *= cosf(degToRad(ray.angle - env->player.angle));
		if (ray.dist > 255)
			ray.dist = 255.0;
		ray.wall_h = (WIN_H * 5) / ray.dist;
		render_slice(&ray, env);
		draw_mm_line(env, (t_v4){env->player.pos.x, env->player.pos.y, \
					ray.pos.x, ray.pos.y}, create_rgb(90, 230, 127));
		ray.angle += env->raycast.a_i;
		ray.count++;
	}
}
