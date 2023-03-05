/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/05 12:32:42 by saeby            ###   ########.fr       */
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
	int	textXPos = floorf((int)(env->map.no_sp.width * ((ray->pos.x / SIZE) + (ray->pos.y / SIZE))) % env->map.no_sp.width);
	float y = env->proj.half_height - ray->wall_h;
	float yIncr = (ray->wall_h * 2) / env->map.no_sp.height;
	int i = 0;
	char	*dst;
	unsigned int color;

	while (i < env->map.no_sp.height)
	{
		dst = env->map.no_sp.addr + ((int)i * env->map.no_sp.line_len + textXPos * env->map.no_sp.bpp / 8);
		color = *(unsigned int *)dst;
		draw_line(env, (t_v4){ray->count, y, ray->count, y + (yIncr + 0.5)}, shade(color, ray->dist));
		y += yIncr;
		i++;
	}
}

static void	render_slice(t_ray *ray, t_env *env)
{
	draw_line(env, (t_v4){ray->count, 0, ray->count, env->proj.half_height - \
				ray->wall_h}, env->map.ceiling);
	// draw_line(env, (t_v4){ray->count, env->proj.half_height - ray->wall_h, \
	// 			ray->count, env->proj.half_height + ray->wall_h}, \
	// 			shade(env->map.wall, ray->dist));
	draw_texture(ray, env);
	draw_line(env, (t_v4){ray->count, env->proj.half_height + ray->wall_h, \
				ray->count, env->proj.half_height + ray->wall_h}, \
				env->map.floor);
}

void	raycasting(t_env *env)
{
	t_ray	ray;

	ray.angle = env->player.angle - env->player.halffov;
	env->raycast.a_i = env->player.fov / env->proj.width;
	ray.count = 0;
	while (ray.count < env->proj.width)
	{
		ray.pos = env->player.pos;
		ray.cos = cosf(degToRad(ray.angle));
		ray.sin = sinf(degToRad(ray.angle));
		set_ray_pos(&ray, env);
		ray.dist = sqrt(pow((env->player.pos.x / SIZE) - (ray.pos.x / SIZE), 2) + \
						pow((env->player.pos.y / SIZE) - (ray.pos.y / SIZE), 2));
		ray.dist *= cosf(degToRad(ray.angle - env->player.angle));
		if (ray.dist > 255)
			ray.dist = 255.0;
		ray.wall_h = env->proj.height / ray.dist;
		render_slice(&ray, env);
		draw_mm_line(env, (t_v4){env->player.pos.x, env->player.pos.y, \
					ray.pos.x, ray.pos.y}, create_rgb(90, 230, 127));
		ray.angle += env->raycast.a_i;
		ray.count++;
	}
}
