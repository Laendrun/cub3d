/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/05 15:02:33 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define TEXT_IDX 3

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
// char *dst;
// unsigned int color;
// dst = env->map.no_sp.addr + ((int)y1 * env->map.no_sp.line_len + (int)x1 * env->map.no_sp.bpp / 8);
// color = *(unsigned int *)dst

void	draw_texture(t_ray *ray, t_env *env)
{
	// if ((int)env->player.angle % 360 > 0 && (int)env->player.angle % 360 < 180)
	// 	texture_id = 2;
	// else if ((int)env->player.angle % 360 > 180 && (int)env->player.angle % 360 < 360)
	// 	texture_id = 0;
	// else if ((int)env->player.angle % 360 > 270 && (int)env->player.angle % 360 < 90)
	// 	texture_id = 1;
	// else if ((int)env->player.angle % 360 > 90 && (int)env->player.angle % 360 < 270)
	// 	texture_id = 3;

	int	textXPos = floorf((int)(env->map.textures[env->texture_id].width * ((ray->pos.x / SIZE) + (ray->pos.y / SIZE))) % env->map.textures[env->texture_id].width);
	float y = env->proj.half_height - ray->wall_h;
	float yIncr = (ray->wall_h * 2) / env->map.textures[env->texture_id].height;
	int i = 0;
	char	*dst;
	unsigned int color;

	while (i < env->map.textures[env->texture_id].height)
	{
		dst = env->map.textures[env->texture_id].addr + ((int)i * env->map.textures[env->texture_id].line_len + textXPos * env->map.textures[env->texture_id].bpp / 8);
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
		if (ray.sin >= 0)
			ray.side = 1;
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
