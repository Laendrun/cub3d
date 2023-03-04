/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 17:55:14 by saeby            ###   ########.fr       */
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

// get texture color based on x y coordinates
// color = *(unsigned int *)env->map.no_sp.addr + ((int)y1 * env->map.no_sp.line_len + (int)x1 * env->map.no_sp.bpp / 8);

void	draw_texture(t_ray *ray, t_env *env)
{
	float	textXPos = (int)(env->map.no_sp.width * (ray->pos.x + ray->pos.y)) % (int)env->map.no_sp.width;
	float y = env->proj.half_height - ray->wall_h;
	float yIncr = (ray->wall_h * 2) / env->map.no_sp.height;
	int i = 0;
	int color;

	while (i < env->map.no_sp.height)
	{
		color = *(unsigned int *)env->map.no_sp.addr + ((int)i * env->map.no_sp.line_len + (int)textXPos * env->map.no_sp.bpp);
		draw_line(env, (t_v4){ray->count, y, ray->count, y + (yIncr + 0.5)}, color);
		y += yIncr;
		i++;
	}
}

static void	render_slice(t_ray *ray, t_env *env)
{
	draw_line(env, (t_v4){ray->count, 0, ray->count, env->proj.half_height - \
				ray->wall_h}, env->map.ceiling);
	draw_line(env, (t_v4){ray->count, env->proj.half_height - ray->wall_h, \
				ray->count, env->proj.half_height + ray->wall_h}, \
				shade(env->map.wall, ray->dist));
	// draw_texture(ray, env);
	draw_line(env, (t_v4){ray->count, env->proj.half_height + ray->wall_h, \
				ray->count, env->proj.half_height + ray->wall_h}, \
				env->map.floor);
}

void	raycasting(t_env *env)
{
	t_ray	ray;

	ray.angle = env->player.angle - env->player.halffov;
	env->raycast.a_i = env->player.fov / WIN_W;
	ray.count = 0;
	while (ray.count < env->proj.width)
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
		ray.wall_h = env->proj.height * 5 / ray.dist;
		render_slice(&ray, env);
		draw_mm_line(env, (t_v4){env->player.pos.x, env->player.pos.y, \
					ray.pos.x, ray.pos.y}, create_rgb(90, 230, 127));
		ray.angle += env->raycast.a_i;
		ray.count++;
	}
}
